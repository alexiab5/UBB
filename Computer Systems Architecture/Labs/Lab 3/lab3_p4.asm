bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 0x3
    b db 0x20
    c db 0x23
    d dd 0xF11764FA
    e dq 0x11764FFFFF123545

segment code use32 class=code
    start:
        ; compute 2/(a+b*c-9)+e-d, a,b,c-byte; d-doubleword; e-qword - signed
        ; result = 
        ; 
        ; ... 
        mov al, [b] ; al = b
        imul byte [c] ; ax = al*c = b*c
        
        mov bx, ax
        mov al, [a]
        cbw ; ax = [a]
        add bx, ax ; bx = a + b*c
        sbb bx, 9 ; bx = a + b*c - 9
        
        mov ax, 2
        cwd ; dx:ax = 2
        idiv bx
        ; ax = dx:ax / bx
        ; dx = dx:ax % bx
        cwde ; eax = ax
        cdq ; edx:eax = ax = 2/(a+b*c-9)
        
        add eax, dword [e]
        adc edx, dword [e+4] ; edx:eax = 2/(a+b*c-9)+e
        mov ebx, eax
        mov ecx, edx ; ecx:ebx = edx:eax
        mov eax, [d]
        cdq ; edx:eax = d
        sbb ebx, eax
        sbb ecx, edx ; ecx:ebx =  2/(a+b*c-9)+e-d
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
