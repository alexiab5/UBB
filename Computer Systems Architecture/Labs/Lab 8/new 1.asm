bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll   
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    n dd 0
    message db "n=", 0
    reading_format db "%d", 0
    printing_format db "n = %d", 0
    
segment code use32 class=code
    start:
        ; printf("n=")
        push dword message
        call [printf]
        add esp, 4*1
        
        ; scanf("%d", n)
        push dword n
        push dword reading_format
        call [scanf]
        add esp, 4*2
        
        ; printf("%d", n)
        push dword [n]
        push dword printing_format
        call [printf]
        add esp, 4*2
        
        push dword 0
        call [exit]