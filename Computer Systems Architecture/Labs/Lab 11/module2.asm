bits 32

; Read from the keyboard a string of numbers, given in the base 10 as signed numbers (a string of characters is read from the keyboard and a string of numbers must be stored in the memory).

global convert_char_to_int

segment data use32 class=code
    is_negative db 0

segment code use32 class=code public
    
convert_char_to_int:
    ; convert_char_to_int(string of digits, number_of_digits) -> edx:eax the integer corresponding to the string of digits
    ; digits_array_address = [esp+4]
    ; number_of_digits = [esp+8]
    mov esi, [esp + 4]
    mov ecx, [esp + 8]
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
ret