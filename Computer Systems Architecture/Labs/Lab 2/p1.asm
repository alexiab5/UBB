bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 4

segment code use32 class=code
    start:
        ; compute 1+15; 4*4
        mov AL, [a] ; AL = a
        mov DL, [a] ; DL = a
        mul DL	    ; AL = AL * DL = a*a
	mov BL, 1   ; BL = 1
	add BL, 15  ; BL = BL + 15 = 1 + 15
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
