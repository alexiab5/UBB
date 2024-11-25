bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 0x3
    b db 0x20
    c db 0x23
    d dd 0x11764F
    e dq 0x11764FFFF

segment code use32 class=code
    start:
        ; compute 2/(a+b*c-9)+e-d, a,b,c-byte; d-doubleword; e-qword - unsigned
        ; result = 1 1753 89B0
        ; 
        ; ... 
        mov al, [b] ; al = b
        mul byte [c] ; ax = al*c = b*c
        
        mov bx, ax
        mov al, [a]
        mov ah, 0 ; ax = [a]
        add bx, ax ; bx = a + b*c
        sub bx, 9 ; bx = a + b*c - 9
        
        mov ax, 2
        mov dx, 0 ; dx:ax = 2
        div bx
        ; ax = dx:ax / bx
        ; dx = dx:ax % bx
        push 0
        push ax
        pop eax ; eax = ax
        mov edx, 0 ; edx:eax = ax = 2/(a+b*c-9)
        
        add eax, dword [e]
        adc edx, dword [e+4] ; edx:eax = 2/(a+b*c-9)+e
        mov ebx, eax
        mov ecx, edx ; ecx:ebx = edx:eax
        mov eax, [d]
        mov edx, 0 ; edx:eax = d
        sub ebx, eax
        sbb ecx, edx ; ecx:ebx =  2/(a+b*c-9)+e-d
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
