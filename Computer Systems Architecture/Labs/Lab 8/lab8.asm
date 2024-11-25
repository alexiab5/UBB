bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf, fopen, fclose, fread              
import exit msvcrt.dll    
import printf msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll


; Read two numbers a and b (in base 10) from the keyboard and calculate a/b. This value will be stored in a variable called "result" (defined in the data segment). The values are considered in signed representation.
segment data use32 class=data
    
    format db "%d", 0
    printing_message db "The two numbers are a = %d, b = %d", 0
    a dd 0
    b dd 0
    result dd 0
    
segment code use32 class=code
    start:        
        ; read the two numbers a and b
        push dword b
        push dword a
        push dword format
        call [scanf]
        add esp, 4 * 3
        
        ; print the result
        push dword [a]
        push dword [b]
        push dword format
        call [printf]
        add esp, 4 * 3
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
