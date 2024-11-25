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

; Se dă un șir de 10 numere în baza 16 în fișierul input.txt. Să se determine cifra minimă din fiecare număr. Să se afișeze acest șir al cifrelor minime, în baza 10, pe ecran.

segment data use32 class=data
    file_name db "input.txt", 0
    access_mode db "r", 0
    count db 10
    hexa_numbers_list times 10 dd 0
    number dd 0
    smallest_digit dd 0
    reading_format db "%x", 0
    printing_format db "%d ", 0
    file_descriptor dd -1

segment code use32 class=code
    
    start:
        ; open the input file for reading
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2 ; clean the stack!!
        mov [file_descriptor], eax
        
        ; check if the file was opened successfully
        cmp eax, 0
        je end
        
        mov edi, hexa_numbers_list
        read: ; read the 10 numbers from the input file
            push dword number
            push dword reading_format
            push dword [file_descriptor]
            call [fscanf]
            add esp, 4*3
            
            cmp eax, 0
            jle end
            
            ; determine the smallest digit
            mov dword [smallest_digit], 16
            mov eax, [number]
            cdq
            mov ecx, 16
            loop_smallest_digit:
                div ecx
                cmp edx, [smallest_digit]
                jae not_smallest
                mov dword [smallest_digit], edx
                not_smallest:
                mov edx, 0
                cmp eax, 0
                jne loop_smallest_digit
            
            push dword [smallest_digit]
            push dword printing_format
            call [printf]
            add esp, 4*2
            
            ; dec byte [count]
            ; cmp byte [count], 0
            ; je end
            
            jmp read
        
    end:
    
        ;close the input file
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
        ; exit(0)
        push dword 0
        call [exit]
    