bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a dw 10
    b dw 20
    c dw 30
    d dw 40

segment code use32 class=code
    start:
        ; compute (a+b+b)+(c-d)
        mov AX, [a] 
        add AX, [b]
        add AX, [b]  ; AX = a+b+b
        mov BX, [c]  
        sub BX, [d]  ; BX = c-d
        add AX, BX   ; AX = AX + BX
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
