bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
extern fopen
extern fclose
extern fread
extern printf
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll


segment data use32 class=data

   fname db 'ip', 0
   mode db 'r', 0
   special db 0
   fmt db '%d'
   
segment code use32 class=code
    start:
        push dword fmode
        push dword fname
        call [fopen]
        
        mov edx, eax ; save the handle
        
        push dword edx
        push dword 1
        push dword 1
        call [fread]
        
        
        cmp eax, 47
        jbe not_special
            inc special
                
        not_special:
        
            push dword special
            push dword fmt
            push edx
            call [fclose]

            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
