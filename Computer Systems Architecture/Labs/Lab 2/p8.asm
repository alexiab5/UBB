bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 10
    e dw 130

segment code use32 class=code
    start:
        ; compute e-a*a
        mov AL, [a]  ; AL = a
        mul BYTE [a] ; AX = AL * a = a*a
        mov BX, [e]  ; BX = e
        sub BX, AX   ; BX = BX - AX = e-a*a
        ; ... 
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
