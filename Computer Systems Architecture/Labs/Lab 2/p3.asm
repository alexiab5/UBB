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
        ; compute a+13-c+d-7+b
        mov AL, [a] ; AL = a
        add AL, 13  ; AL = AL + 13 = a+13
        sub AL, [c] ; AL = AL - c = a+13-c
        add AL, [d] ; AL = AL + d = a+13-c+d
        sub AL, 7   ; AL = AL - 7 = a+13-c+d-7
        add AL, [b] ; AL = AL + b = a+13-c+d-7+b
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
