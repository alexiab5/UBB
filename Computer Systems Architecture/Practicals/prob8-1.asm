; Citesc string de la tastatura, creem fisier string.txt, adaugam in fisier prima data majusculele apoi minusculele invers de cum apar in sir.

bits 32

global start

extern exit, fopen, fclose, scanf, fprintf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    access_mode db "w", 0
    file_name db "string15.txt", 0
    file_descriptor dd -1
    message1 db "Enter a string: ", 0
    message2 db "Successfully created the new file!", 10, 0
    reading_format db "%s", 0
    printing_format db "%c", 0
    resb 0
    lowercase_array times 50 db 0 
    string times 50 db 0
    new_line dd 0x0A
    
segment code use32 class=code

    start:
        ; create the new file
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je end
        
        push dword message2
        call [printf]
        add esp, 4
        
        ; read the string from the keyboard
        push dword message1
        call [printf]
        add esp, 4
        
        push dword string
        push dword reading_format
        call [scanf]
        add esp, 4*2
        
        ; print the uppercase letters and create the array of lowercase letters
        mov esi, string
        mov edi, lowercase_array
        repeat:
            mov al, [esi]
            cmp al, 'A'
            jb et1
                cmp al, 'Z'
                ja et2
                push eax
                mov ebx, 0
                mov bl, al
                
                push ebx
                push dword printing_format
                push dword [file_descriptor]
                call [fprintf]
                add esp, 4*3
                
                pop eax
                jmp et1
            et2:
            cmp al, 'a'
            jb et1
                cmp al, 'z'
                ja et1
                mov [edi], al
                inc edi
            et1:
            inc esi
            cmp al, 0
            jne repeat
            
        ; print the lowercase letters
        mov esi, lowercase_array
        cld
        repeat2:
            lodsb
            cmp al, 0
            jne repeat2
        dec esi
        dec esi
        std
        printing_lowercase:
            mov ebx, 0
            mov bl, [esi]
            dec esi
            push ebx
            push dword printing_format
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*3
            
            cmp bl, 0
            jne printing_lowercase
            
        ; close the file
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
    end:
        push dword 0
        call [exit]