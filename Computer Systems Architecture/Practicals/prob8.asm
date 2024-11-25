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
    file_name db "input.txt", 0
    file_descriptor dd -1
    message1 db "Enter a string: ", 0
    message2 db "Successfully created the new file!", 0
    
segment code use32 class=code

    start:
        
        ; create the new file
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je end
        
        mov [file_descriptor], eax
        
        push dword message2
        call [printf]
        add esp, 4
        
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
    end:
        push dword 0
        call [exit]