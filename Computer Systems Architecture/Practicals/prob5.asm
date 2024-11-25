bits 32

global start

extern exit, printf, scanf, fprintf, fscanf, fread, fopen, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fscanf msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

; Se citeste de la tastatura un sir de caractere (litere mici si litere mari, cifre, caractere speciale, etc). Sa se formeze un sir nou doar cu literele mici si un sir nou doar cu literele mari. Sa se afiseze cele 2 siruri rezultate pe ecran.

segment data use32 class=data

    chars_string times 50 db 0 
    message1 db "Enter a string of characters: ", 0
    message2 db "The lowercase letters in the string: %s%c", 0
    message3 db "The uppercase letters in the string: %s%c", 0
    newline db 0Ah, 0
    uppercase_letters_count dd 0
    lowercase_letters_count dd 0
    uppercase times 50 dd 0
    lowercase times 50 dd 0
    reading_format db "%s", 0
    printing_format db "%s", 0
    file_descriptor dd -1

segment code use32 class=code
    
    start:
        
        push message1
        call [printf]
        add esp, 4
        
        push chars_string
        push reading_format
        call [scanf]
        add esp, 4*2
        
        mov esi, chars_string
        repeat:
            lodsb
            
            cmp al, "A"
                jb not_letter
                    cmp al, "Z"
                    ja upper
                    ; uppercase letter ("A" <= AL <= "Z")
                    mov ebx, [uppercase_letters_count]
                    mov [uppercase + ebx], al
                    inc dword [uppercase_letters_count]
                    jmp not_letter
                    upper:
                        cmp al, "a"
                        jb not_letter
                        cmp al, "z"
                        ja not_letter
                        ; lowercase letter ("a" <= AL <= "z")
                        mov ebx, [lowercase_letters_count]
                        mov [ebx + lowercase], al
                        inc dword [lowercase_letters_count]  
                not_letter:
                
            cmp al, 0
            jne repeat
        
        push newline
        push lowercase
        push message2
        call [printf]
        add esp, 4*3
        
        push newline
        push uppercase
        push message3
        call [printf]
        add esp, 4*3
        
        push dword 0
        call [exit]