bits 32
;alink module1.obj module2.obj -oPE -subsys console -entry start
global start

extern exit, scanf, printf
extern convert_char_to_int

import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data public
    numbers_char times 51 db 0 
    numbers_int times 25 dd 0
    message1 db "Enter the string of numbers in base 10, separated by commas:" , 0
    message2 db "The numbers are: %s", 0
    format db "%s", 0
    format2 db "%d ", 0
    number times 10 db 0 ; '-','1','0','2','0','0'
    number_of_digits db 0
    current_index db 0
    numbers_char_current_index dd 0
        
; Read from the keyboard a string of numbers, given in the base 10 as signed numbers (a string of characters is read from the keyboard and a string of numbers must be stored in the memory).
; "50,-50,100,-10200,92,1,0" 

segment code use32 class=code public
    start:
        push dword message1
        call [printf]
        add esp, 4*1 ; cleaning the stack
        
        ; scanf(format, value)
        push dword numbers_char
        push dword format
        call [scanf]
        add esp, 4*2
        
        ; parse the string of numbers and convert each number into an integer
        mov esi, numbers_char
        mov [numbers_char_current_index], esi
        mov edi, number
        repeat1:
            lodsb
            inc dword [numbers_char_current_index]
            cmp al, 0
            jz end_of_loop
            cmp al, ','
            jnz not_end_of_number
            ;convert_char_to_int(string of digits, number_of_digits) -> eax the integer corresponding to the string of digits
                mov ebx, 0
                mov bl, [number_of_digits]
                push ebx
                push dword number
                call convert_char_to_int
                add esp, 4*2
                mov edi, number
                mov esi, [numbers_char_current_index]
                mov byte [number_of_digits], 0
                mov ecx, 0
                mov cl, [current_index]
                mov [numbers_int + ecx], eax
                add byte [current_index], 4
                jmp repeat1
            not_end_of_number:
                stosb
                inc byte [number_of_digits]
        jmp repeat1
    end_of_loop:
    
        ;convert the last number in the string
        mov ebx, 0
        mov bl, [number_of_digits]
        push ebx
        push dword number
        call convert_char_to_int
        add esp, 4*2
        mov ecx, 0
        mov cl, [current_index]
        mov [numbers_int + ecx], eax
        
        ;printing
        mov esi, numbers_int
        repeat2:
            lodsd
            cmp eax, 0
            jz end_of_loop2
            ;printf(format, value)
            push eax
            push dword format2
            call [printf]
            add esp, 4*2
        jmp repeat2
    end_of_loop2:
        push dword 0
        call [exit]
    