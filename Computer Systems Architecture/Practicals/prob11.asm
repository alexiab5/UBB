; Se citesc cuvinte de la tastatura, sa se creeze un fisier cu numele primului .txt si restul sa se afiseze in acest fisier cu literele inversate

bits 32
global start
extern exit, fopen, fclose, scanf, printf, fprintf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fprintf msvcrt.dll

segment data use32 class=data
    access_mode db "w", 0
    message1 db "Enter a sentence: ", 0
    message2 db "success", 0
    file_name times 20 db 0
    extention db ".txt", 0
    file_descriptor dd -1
    format db "%s", 0
    format2 db "%s ", 0
    string times 50 db 0
    reversed_string times 50 db 0
    
segment code use32 class=code
    start:
        push dword message1
        call [printf]
        add esp, 4
        
        ; read the first word
        push dword file_name
        push dword format
        call [scanf]
        add esp, 4*2
        
        ; determine the output file name
        mov esi, file_name
        cld
        repeat1:
            cmp byte [esi], 0
            je et1
            lodsb
            jmp repeat1
        et1:
        mov ebx, [extention]
        mov dword [esi], ebx
        
        ; open the file
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        cmp eax, 0
        je end
        
        push dword message1
        call [printf]
        add esp, 4
        
        ; read the rest of the sentence
        read_loop:
            push dword string
            push dword format
            call [scanf]
            add esp, 4*2
            
            cmp byte [string], '.'
            je finished_reading
            
            ; push dword string
            ; push dword format
            ; call [printf]
            ; add esp, 4*2
            
            cld
            mov esi, string
            repeat2:
                cmp byte [esi], 0
                je et2
                lodsb
                jmp repeat2
            et2:
            ; reverse the current word
            dec esi
            std
            mov edi, reversed_string
            inverse_word:
                lodsb
                mov [edi], al
                inc edi
                cmp al, 0
                jne inverse_word
            mov byte [edi], 0
            
            ; print the reversed word to the output file
            push dword reversed_string
            push dword format2
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*3
            
            jmp read_loop
            
    finished_reading:
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
    end:
        push dword 0
        call [exit]