bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll   
import printf msvcrt.dll
import scanf msvcrt.dll

;Read two numbers a and b (in base 10) from the keyboard and calculate a/b. This value will be stored in a variable called "result" (defined in the data segment). The values are considered in signed representation.

segment data use32 class=data
    a dd 0
    b dd 0
    result dd 0
    message1 db "a=", 0
    message2 db "b=", 0
    reading_format db "%d", 0
    printing_format db "%d/%d=%d remainder %d", 0
    
segment code use32 class=code
    start:
        ; printf(message1)
        push dword message1
        call [printf]
        add esp, 4*1 ; cleaning the stack
        
        ; scanf("%d", a)
        push dword a
        push dword reading_format
        call [scanf]
        add esp, 4*2
        
        ; printf(message2)
        push dword message2
        call [printf]
        add esp, 4*1
        
        ; scanf("%d", b)
        push dword b
        push dword reading_format
        call [scanf]
        add esp, 4*2
        
        ;compute a/b
        mov eax, dword [a]
        cdq
        idiv dword [b]
        cmp edx, 0
        jge positive_remainder
        imul edx, -1
    positive_remainder:
        
        ; printf(printing_format, a, b, eax, edx)
        push edx
        push eax
        push dword [b]
        push dword [a]
        push dword printing_format
        call [printf]
        add esp, 4*5
        
        push dword 0
        call [exit]