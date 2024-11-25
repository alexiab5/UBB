bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 0x20
    b dw 0xFDE
    c dd 0x23E7
    d dq 0x11764FFF

segment code use32 class=code

    start:
        ; compute (c+b)-a-(d+d), a - byte, b - word, c - double word, d - qword, signed
        ; => FFFF FFFF DD13 93A7
        ; ... 
        mov ax, [b]
        cwde ; eax = b
        mov ebx, [c]
        add ebx, eax ; ebx = ebx + eax = c+b
        
        mov al, [a]
        cbw ; ax = al = a
        cwde ; eax = ax = a
        sub ebx, eax ; ebx = ebx - eax = (c+b)-a
        
        mov eax, ebx ; eax = ebx
        cdq ; edx:eax = (c+b)-a
        
        mov ebx, dword [d]
        mov ecx, dword [d+4] ; ecx:ebx = d
        add ebx, dword [d]
        adc ecx, dword [d+4] ; ecx:edx = d+d
        
        sub eax, ebx 
        sbb edx, ecx ; edx:eax = edx:eax - ebx:ecx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
