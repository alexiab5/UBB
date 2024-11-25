bits 32 
global start        

extern exit               ; exits program
import exit msvcrt.dll    
                          
segment data use32 class=data
    a db 0x20
    b dw 0xFDED
    c dd 0x23E76
    d dq 0x11764FFF

segment code use32 class=code
    start:
        ; compute (c+b)-a-(d+d), a - byte, b - word, c - double word, d - qword, signed
        ; => 
        ; ... 
        mov ax, [b]
        cwd ; dx:ax = b
        push dx
        push ax
        pop ecx ; ecx = dx:ax = b
        mov ebx, [c]
        add ebx, ecx ; ebx = ebx + ecx = c+b
        mov al, [a]
        cbw ; ax = al = a
        cwd ; dx:ax = ax = a
        push dx
        push ax
        pop ecx ; ecx = dx:ax = a
        sub ebx, ecx ; ebx = ebx - ecx = (c+b)-a
        mov eax, ebx ; eax = ebx
        cdq ; edx:eax = (c+b)-a
        mov ecx, [d]
        mov ebx, dword [d+4]
        add ecx, [d]
        adc ebx, dword [d+4] ; ebx:ecx = d+d
        sub eax, ecx 
        sbb edx, ebx ; edx:eax = edx:eax - ebx:ecx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
