bits 32 ; assembling for the 32 bits architecture
; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data

    A db 10101010b
    B dw 1111111100000000b
    C resd 1

    ;Given the byte A and the word B, compute the doubleword C as follows:

segment code use32 class=code
    start:
        mov ebx, 0 ; we compute the result in ebx
        ; the bits 0-7 of C have the value 1
        or bx, 00FFh ; we force to 1 the bits 0-7 => bx = 0000000011111111b
        
        ; the bits 8-11 of C are the same as the bits 4-7 of A
        mov al, [A]
        and ax, 0000000011110000b ; we isolate the bits 4-7 of A
        mov cl, 4
        rol ax, cl ; we rotate the bits 4 positions to the left
        or bx, ax ; we put the bits into the result => bx = 0000101011111111b
        
        ; the bits 12-19 are the same as the bits 2-9 of B
        mov eax, 0
        mov ax, [B]
        and ax, 00000001111111100b ; we isolate the bits 2-9 of B
        shl eax, 10 ; we shift the bits 10 positions to the left 
        or ebx, eax ; we put the bits into the result => ebx = 0000000000001100 0000101011111111b
        
        ; the bits 20-23 are the same as the bits 0-3 of A 
        mov eax, 0
        mov al, [A]
        and ax, 000Fh ; we isolate bits 0-3 of A
        shl eax, 20 ; we shift the bits 20 positions to the left 
        or ebx, eax ; we put the bits into the result => ebx = 0000000010101100 0000101011111111b
        
        ; the bits 24-31 are the same as the high byte of B
        mov eax, 0
        mov ax, [B]
        and ax, 1111111100000000b ; we isolate the high byte of B
        rol eax, 16 ; we rotate the bits 16 positions to the left
        or ebx, eax ; we put the bits into the result => ebx = 1111111110101100 0000101011111111b
        
        mov [C], ebx ; we move the result in C
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
