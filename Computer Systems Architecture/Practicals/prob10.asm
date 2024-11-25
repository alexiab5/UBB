; Se citeste de la tastatura m,n apoi m numere zecimale, pe linii diferite. Sa se afiseze nr cu cel putin n cifre pare in output.txt.

bits 32

global start

extern exit, scanf, fopen, fclose, fprintf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    access_mode db "w", 0
    file_name_out db "output.txt", 0
    file_descriptor dd -1
    message1 db "n=", 0
    message2 db "m=", 0
    message3 db "Enter %d numbers:", 10, 0
    format1 db "%d", 0
    format2 db "%d ", 0
    n dd 0
    m dd 0
    number dd 0
    count_digits dd 0
    
segment code use32 class=code
    start:
        push dword message1
        call [printf]
        add esp, 4
        
        push dword n
        push dword format1
        call [scanf]
        add esp, 4*2
        
        push dword message2
        call [printf]
        add esp, 4
        
        push dword m
        push dword format1
        call [scanf]
        add esp, 4*2

        ; open the output file
        push dword access_mode
        push dword file_name_out
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        cmp eax, 0
        je end
        
        push dword [m]
        push dword message3
        call [printf]
        add esp, 4*3
        
        read_write:
            push dword number
            push dword format1
            call [scanf]
            add esp, 4*2
            
            ; count the number of even digits in the number
            mov eax, [number]
            mov dword [count_digits], 0
            loop_digits:
                cdq
                mov ecx, 10
                div ecx
                mov ebx, eax
                
                mov eax, edx
                mov edx, 0
                mov ecx, 2
                div ecx
                cmp edx, 1
                je is_odd
                    inc dword [count_digits]
                is_odd:
                
                mov eax, ebx
                cmp eax, 0
                jne loop_digits
            
            ; if the number has n even digits, print it in the output file
            mov ebx, [count_digits]
            cmp ebx, [n]
            jne not_good
                push dword [number]
                push dword format2
                push dword [file_descriptor]
                call [fprintf]
                add esp, 4*3
            not_good:
            
            dec dword [m]
            cmp dword [m], 0
            jne read_write
            
            
        push dword [file_descriptor]
        call [fclose]
        add esp, 4

    end:
        push dword 0
        call [exit]
    