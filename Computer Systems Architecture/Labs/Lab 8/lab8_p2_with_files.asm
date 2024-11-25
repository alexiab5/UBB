bits 32

global start

extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import fopen msvcrt.dll
import printf msvcrt.dll

; A text file is given. Read the content of the file, count the number of consonants and display the result on the screen. The name of text file is defined in the data segment.

segment data use32 class=data
    file_name db "input.txt", 0
    access_mode db "r", 0
    file_descriptor dd -1
    len equ 100                 ; maximum number of characters to read
    text times (len+1) db 0     ; string to store the text read from file
    format db "We've read %d characters from file. The number of consonants found is %d.", 0
    count dd 0
    consonants dd 0
    characters_read dd 0
    vowels db "AEIOUaeiou", 0

segment code use32 class=code
    start:
        ; open the file for reading
        ; fopen(file_name, access_mode)
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        mov [file_descriptor], eax
        
        ; check if fopen() has successfully created the file (EAX != 0)
        cmp eax, 0
        je end1
        
        ; loop to read the contents of the file in stages (100 chars at a time)
        read_text:
            ; fread(str, size, count, fd) => fread(text, 1, len, file_descriptor)
            push dword [file_descriptor]
            push dword len
            push dword 1
            push dword text
            call [fread]
            add esp, 4*4
            
            cmp eax, 0 ; check if we reached the end of the file (no chars were read)
            jz finished_reading
            
            mov [count], eax ; eax = number of chars read from the file
            add dword [characters_read], eax
            ; count the number of consonants from the text
            ; loop to parse the string
            mov ecx, [count]
            jecxz end1
            mov esi, text
            repeat:
                lodsb ; ax = the current character
                ; check ax is letter
                ; check 'A' <= ax <= 'z'
                cmp ax, 'A'
                jb not_consonant
                    cmp ax, 'z'
                    ja not_consonant
                    ; check ax is not special character
                    cmp ax, 'Z'
                    jb lowercase
                        cmp ax, 'a'
                        jb not_consonant
                lowercase:
                    push ecx
                    push esi
                    ; loop to check ax is not a vowel
                    mov ecx, 10 ; 10 = total number of vowels
                    mov bx, ax 
                    mov esi, vowels
                    repeat1:
                        lodsb
                        cmp ax, bx
                        jz vowel
                    loop repeat1
                    inc byte [consonants]
                vowel:
                    pop esi
                    pop ecx
        not_consonant:
            loop repeat

            jmp read_text
            
    finished_reading:
        ; close the file
        ; fclose(fd)
        push dword [file_descriptor]
        call [fclose]
        add esp, 4*1
        
        ; printf(format, value1, value2)
        push dword [consonants]
        push dword [characters_read]
        push dword format
        call [printf]
        add esp, 4*3
        
    end1:
        push dword 0
        call [exit]