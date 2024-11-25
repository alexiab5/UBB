bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 10
    b db 20
    c db 5
    d dw 40
    aux db 2
    aux1 db 4

segment code use32 class=code
    start:
        ; compute (a+b)/2 + (10-a/c) + b/4
        mov AL, [a]
        add AL, [b] ; AL = a+b
        mov AH, 0   ; AH = 0 => AX = AL
        div BYTE [aux]  ; AX = (a+b)/2
        mov BX, AX   ; BX = AX
        mov AL, [a]  ; AL = [a]
        mov AH, 0    ; AH = 0 = > AX = AL
        div BYTE [c] ; AX = AX / c
        mov DX, 10   ; DX = 10
        sub DX, AX   ; DX = DX - AX = 10 - a/c
        add BX, DX   ; BX = BX + CX = (a+b)/2 + (10-a/c)
        mov AL, [b]  ; AL = b
        mov AH, 0    ; AX = AL
        div byte [aux1] ; AX = AX / aux1 = b/4
        add BX, AX   ; BX = BX + AX 
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
