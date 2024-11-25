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

; Se citește de la tastatură un număr N și apoi N numere. Să se calculeze suma numerelor pare introduse, să se calculeze suma numerelor impare introduse, apoi diferența dintre cele două sume. Să se afișeze în fișierul output.txt cele 3 rezultate, în baza 16, pe linii separate.


segment data use32 class=data
    file_name db "out2.txt", 0
    access_mode db "w", 0
    reading_format db "%d", 0
    printing_format db "%x%s", 0
    new_line db 10, 0
    file_descriptor dd -1
    message1 db "n=", 0
    message2 db "Enter %d numbers: ", 0
    n dd 0
    number dd 0
    even_sum dd 0
    odd_sum dd 0
    sum_diference dd 0
    
segment code use32 class=code
    
    start:
        push dword message1
        call [printf]
        add esp, 4*1
        
        push dword n
        push dword reading_format
        call [scanf]
        add esp, 4*2
        
        push dword [n]
        push dword message2
        call [printf]
        add esp, 4*2
        
        cmp dword [n], 0
        jbe end
        ; loop to read n numbers
        read:
            push dword number
            push dword reading_format
            call [scanf]
            add esp, 4*2
            
            mov eax, [number]
            cdq
            mov ecx, 2
            div ecx
            mov eax, [number]
            cmp edx, 1
            je is_odd
                clc
                adc [even_sum], eax
                add eax, 0
                jmp is_even
            is_odd:
            clc
            adc [odd_sum], eax
            add eax, 0
            is_even:
            dec dword [n]
            cmp dword [n], 0
            jne read
        
    end:
        mov eax, [even_sum]
        sbb eax, [odd_sum]
        sub eax, 0
        mov [sum_diference], eax
        
        push dword new_line
        push dword [even_sum]
        push dword printing_format
        call [printf]
        add esp, 4*3
        
        push dword new_line
        push dword [odd_sum]
        push dword printing_format
        call [printf]
        add esp, 4*3
        
        push dword new_line
        push dword [sum_diference]
        push dword printing_format
        call [printf]
        add esp, 4*3
        
        ; push dword access_mode
        ; push dword file_name
        ; call [fopen]
        ; add esp, 4*2
        
        ; cmp eax, 0
        ; je end2
        ; mov [file_descriptor], eax
        
        ; push dword [even_sum]
        ; push dword printing_format
        ; push dword [file_descriptor]
        ; call [fprintf]
        ; add esp, 4*3
        
        ; push dword [odd_sum]
        ; push dword printing_format
        ; push dword [file_descriptor]
        ; call [fprintf]
        ; add esp, 4*3
        
        ; push dword [sum_diference]
        ; push dword printing_format
        ; push dword [file_descriptor]
        ; call [fprintf]
        ; add esp, 4*3
        
        ; push dword [file_descriptor]
        ; call [fclose]
        ; add esp, 4*1
    ; end2:
        push dword 0
        call [exit]