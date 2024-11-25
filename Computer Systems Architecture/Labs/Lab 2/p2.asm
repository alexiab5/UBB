bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 10
    b db 20
    c db 30
    d db 40

segment code use32 class=code
    start:
        ; compute (b+b)+(c-a)+d
        mov AL, [b] ; AL = b
        add AL, [b] ; AL = AL + b = b + b
        mov AH, [c] ; AH = c
        sub AH, [a] ; AH = AH - a = c - a
        add AL, AH  ; AL = AL + AH
        add AL, [d] ; AL = AL + d
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
