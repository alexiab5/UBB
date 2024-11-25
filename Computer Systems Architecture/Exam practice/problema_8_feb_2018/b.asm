bits 32

global print_double

extern printf
import printf msvcrt.dll

segment data use32 class=data
    byte_string times 32 db "0"
    db 0 ; string ends with 0
    format db "%s",10,0
    
segment code use32 class=code public
; print in base 2 the doubleword at [esp+4]
print_double:
    mov eax, [esp + 4]
    mov edi, byte_string
    mov ecx, 32
    get_bits:
        mov byte [edi], "0"
        shl eax, 1
        adc byte [edi], 0
        inc edi
    loop get_bits
    
    push dword byte_string
    push dword format
    call [printf]
    add esp, 4*2
    
    ret
        