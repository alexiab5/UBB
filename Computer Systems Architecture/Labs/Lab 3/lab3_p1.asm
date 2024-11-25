bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 10h
    b dw 2513h
    c dd 3026AFh
    d dq 3026AFFABFFh

segment code use32 class=code
    start:
        ; compute (b+b)+(c-a)+d, a - byte, b - word, c - double word, d - qword, unsigned
        ; result = 302 6B30 1CC4
        ; ... 
        mov ax, [b] ; ax = b
        add ax, [b] ; ax = b + b
        
        mov ebx, 0  
        mov bl, [a] ; ebx = a
        mov ecx, [c] ; ecx = c
        sub ecx, ebx ; ecx = c - a
        add cx, ax ; cx = ax
        adc ecx, 0 ; ecx = (b+b)+(c-a)
        
        mov eax, dword [d] 
        mov ebx, dword [d+4] ; ebx:eax = d
        add eax, ecx 
        adc ebx, 0   ; ebx:eax = ebx:eax + ecx = (b+b)+(c-a)+d
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
