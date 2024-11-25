bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data

    A dw 1010101010101010b
    B dw 1111111100000000b
    C resd 1

    ;Given the words A and B, compute the doubleword C as follows:
segment code use32 class=code
    start:
        mov ebx, 0 ; we compute the result in ebx
        ; the bits 0-3 of C are the same as the bits 5-8 of B
        mov ax, [B] 
        and ax, 0000000111100000b ; we isolate the bits 5-8 of B
        shr ax, 5 ; we shift the bits 5 positions to the right
        or bx, ax ; we put the bits into the result => bx = 0000000000001000b
        
        ; the bits 4-8 of C are the same as the bits 0-4 of A
        mov ax, [A]
        and ax, 0000000000011111b ; we isolate the bits 0-4 of A
        shl ax, 4 ; we shift the bits 4 positions to the left
        or bx, ax ; we put the bits into the result => bx = 0000000010101000b
        
        ; the bits 9-15 of C are the same as the bits 6-12 of A
        mov eax, 0
        mov ax, [A]
        and ax, 0001111111000000b ; we isolate the bits 6-12 of A
        mov cl, 3
        rol ax, cl ; we rotate the bits 3 positions to the left 
        or ebx, eax ; we put the bits into the result => bx = 0101010010101000b
        
        ; the bits 16-31 of C are the same as the bits of B
        mov eax, 0
        mov ax, [B]
        mov cl, 16 
        ror eax, cl; we rotate the bits 16 positions to the right 
        or ebx, eax ; we put the bits into the result => ebx = 1111111100000000 0101010010101000b
        
        mov [C], ebx ; we move the result in C
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
