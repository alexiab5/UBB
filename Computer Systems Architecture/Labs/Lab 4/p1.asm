bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    A db 00011001b ; A = 25d
    B resb 1
    C resd 1
    n resb 1
    
segment code use32 class=code
    start:
        ;Given the byte A, obtain the integer number n represented on the bits 2-4 of A.
        
        mov al, [A] ; al = A = 00011001b = 25d
        shr al, 2   ; al = 00000110b = 6d
        and al, 0Fh ; al = 00000110b = 6d
        mov [n], al ; n = 00000110b = 6d
        
        ;Then obtain the byte B by rotating A n positions to the right.
        mov al , [A] ; al = A = 00011001b
        mov cl, [n] ; cl = 6d
        ror al, cl ; al = 01100100b = 100d
        mov [B], al ; B = 01100100b = 100d
        
        ;Compute the doubleword C.
        ;We compute the result in ebx
        ;the bits 8-15 of C are 0
        
        mov ebx, 0
        
        ;the bits 16-23 of C are the same as the bits of B
        mov bx, [B] ; bx = 01100100b = 100d
        shl ebx, 16 ; we shift the bits of ebx 16 positions to the left
        
        ;the bits 24-31 of C are the same as the bits of A
        mov eax, 0
        mov al, [A] ; al = A = 25d = 19h
        shl eax, 24 ; we shift the bits of eax so that the last 8 bits are brought at the beginning

        or ebx, eax ; we put the bits in the result
        
        ;the bits 0-7 of C have the value 1
        or ebx, 000000FFh 
        
        mov [C], ebx ;we move the result in C
        ; C = 0001100111001000000000011111111b
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
