bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;Given the word A, compute the doubleword B
    A dw 281 ; A = 0001 0001 1001b
    B resd 1

; our code starts here
segment code use32 class=code
    start:
        ;we compute the result in ebx
        ;the bits 28-31 of B have the value 1
        mov ebx, 0
        or ebx, 11110000000000000000000000000000b ; 1FFFFFFh
        
        ;the bits 24-25 are the same as the bits 8-9 of A
        mov eax, 0
        mov ax, [A] ; ax = A = 00000001 00011001
        and eax, 00000000000000000000001100000000b
        ;we isolate the bits 8-9
        shl eax , 16 ; we put the bits 8-9 on the positions 24-25 
        or ebx, eax ; we put the bits into the result
        
        ;the bits 26-27 are the same as the bits 8-9 of A
        shl eax, 2 ; we put the bits on positions 24-25 from eax on positions 26-27 
        or ebx, eax ; we put the bits into the result
        
        ;the bits 20-23 of B are the invert of the bits 0-3 of A 
        mov eax, 0 
        mov ax, [A]
        not eax ;we inverse the bits in A
        and eax, 0000000Fh ;we force to zero the bits 4-31
        shl eax, 20 ;we shift the bits so that bits 0-3 are on positions 20-23
        or ebx, eax ;we put the bits into the result
        
        ;the bits 16-19 of B have the value 0
        ;we already did that when we initialised ebx with 0
        
        ;the bits 0-15 of B are the same as the bits 16-31 of B
        mov eax, ebx
        shr eax, 16 ;we put the bits 16-31 on positions 0-15
        or ebx, eax ;we put the bits into the result
        
        ; we move the result in B
        mov [B], ebx
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
