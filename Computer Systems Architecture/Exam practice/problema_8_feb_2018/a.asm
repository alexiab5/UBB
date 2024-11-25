bits 32

global start

extern exit 
import exit msvcrt.dll
extern print_double

segment data use32 class=data public
    s dq 00000000FFFFFFFFh, 11111101010101010101010111b, 01010101010111b
    len equ ($-s)/8
    res times len dd 0
    result_count dd 0
    
segment code use32 class=code public
    
start:
    mov ecx, len
    jecxz end1
    mov esi, s
    printing:
        lodsd
        push ecx
        
        push eax
        call print_double
        add esp, 4
        
        pop ecx
    
    loop printing
    
    end1:
    push dword 0
    call [exit]