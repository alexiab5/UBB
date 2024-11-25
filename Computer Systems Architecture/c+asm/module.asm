bits 32

; Read from the keyboard a string of numbers, given in the base 10 as signed numbers (a string of characters is read from the keyboard and a string of numbers must be stored in the memory).

global _convert_char_to_int

segment data public data use32
    is_negative db 0
    result dd 0

segment code public code use32
    
_convert_char_to_int:
    ; convert_char_to_int(string_of_digits, number_of_digits) -> eax = the integer corresponding to the string of digits
    ; digits_array_address = [esp+4]
    ; number_of_digits = [esp+8]
    ; create a stack frame
    push ebp
    mov ebp, esp
    pushad
    
    ; retreive the function's arguments from the stack
    mov esi, [ebp + 8]
    mov ecx, [ebp + 12]
    
    mov byte [is_negative], 0
    mov eax, 0
    jecxz end_of_loop
    repeat:
        mov ebx, 0
        mov bl, [esi]
        inc esi
        cmp bl, '-'
        jnz is_digit
            mov byte [is_negative], 1
            jmp not_digit
        is_digit:
        sub bl, '0'
        imul eax, 10
        add eax, ebx
        not_digit:
    loop repeat
    ; check if the number is negative
    cmp byte [is_negative], 1
    jnz end_of_loop
    imul eax, -1
    
    end_of_loop:
    mov [result], eax
    ; restore the stack frame
    popad
    mov eax, [result]
    mov esp, ebp
    pop ebp
    
    ret