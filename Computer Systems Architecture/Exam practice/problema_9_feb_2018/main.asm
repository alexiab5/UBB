bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    s dq 00000000FFFFFFFFh, 11111101010101010101010111b
    len equ ($-s)/8
    res times len dd 0
    byte_string times 32 db "0"
    db 0 ; string ends with 0
    format db "%s",10,0
    result_count dd 0
    
segment code use32 class=code

count_sequences1:
    mov ecx, 32
    mov eax, 0 ; final count
    mov ebx, [esp+4]
    mov edx, 0 ; count pe parcurs
    .repeat1:
        shl ebx, 1 ; the first bit of ebx is now in CF
        push edx ; that's how we will check the bit was 0, by remembering the value of edx before the incrementation
        adc edx, 0
        cmp edx, 3
        jne .not_sequence
        inc eax ; we found a new sequence of "111"
        jmp .reset
        .not_sequence:
        cmp edx, [esp] ; if edx was not increased => the bit was 0 so we need to reset the count 
        je .reset
        jmp .not_reset
        .reset:
        mov edx, 0
        .not_reset:
        add esp, 4
    loop .repeat1
    ; the output i.e the number of distinct sequences is in eax
    ret
    
start:
    mov ecx, len
    mov esi, s
    mov edi, res
    cld
    build_string:
        lodsd ; eax = the low double word of the current quad
        push ecx
        
        push eax
        call count_sequences1
        add esp, 4
        
        pop ecx
        
        cmp eax, 2
        jb not_valid
            mov eax, [esi - 4] ; esi was already incremented, now it points to the high doubleword
            stosd ; store the valid doublewords in the result string
            inc dword [result_count]
        not_valid:
        lodsd 
    
    loop build_string

    mov ecx, [result_count]
    ;mov ecx, len
    jecxz end1
    mov esi, res
    ;mov esi, s
    printing:
        mov edi, byte_string
        lodsd
        push ecx
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
        
        pop ecx
    
    loop printing
    
    end1:
    push dword 0
    call [exit]