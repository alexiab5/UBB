bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 10
    b dw 20
    c dd 30
    d dq 40

segment code use32 class=code
    start:
        ; compute (b+b)+(c-a)+d
        ; ... 
        mov ax, [b] ; ax = b
        add ax, [b] ; ax = b + b
        
        mov ebx, 0  ; ebx = 0
        mov bl, [a] ; bl = a => ebx = a
        mov ecx, [c] ; ecx = c
        sub ecx, ebx ; ecx = c - a
        add cx, ax ; cx = ax
        adc ecx, 0 ; adding the carry flag
        mov eax, dword [d] 
        mov ebx, dword [d+4] ; ebx:eax = d
        add eax, ecx 
        adc ebx, 0   ; ebx:eax = d + ecx 
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
