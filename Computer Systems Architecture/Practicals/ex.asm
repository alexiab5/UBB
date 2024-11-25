;DONE
;A text file is given. The text file contains numbers (in base 10) separated by spaces.
; Read the content of the file, determine the maximum number (from the numbers that have been read) and write the result at the
; end of file.
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fprintf,fread,fclose,fopen,fscanf,atoi       
import exit msvcrt.dll  
import fprintf msvcrt.dll   
import fread msvcrt.dll   
import fclose msvcrt.dll   
import fopen msvcrt.dll
import fscanf msvcrt.dll  
import atoi msvcrt.dll   ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file_in_name db "input.txt",0
    file_out_name db "out.txt",0
    source_file_in dd -1
    source_file_out dd -1
    acces_mode_read db "r",0
    acces_mode_write db "w",0
    len equ 100
    text times (len+1) db 0
    maximum dd 0
    format db "%d",0
    number dd 0
    
   

; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword acces_mode_read
        push dword file_in_name
        call [fopen]
        add esp,4*2
        
        cmp eax,-1
        je final
        
        mov [source_file_in],eax
        
        push dword acces_mode_write
        push dword file_out_name
        call [fopen]
        add esp,4*2
        
        cmp eax,-1
        je final
        
        mov [source_file_out],eax
        
        mov ebx,[maximum]
        read:
            push dword number
            push dword format
            push dword [source_file_in]
            call [fscanf]
            add esp,4*3
            
            cmp eax,-1
            je final
            
            mov edx,[number]
            
            loop_maximum:
                cmp edx,ebx
                jng read
             
             mov ebx,edx
             jmp read
              
       final: 
     push ebx
     push dword format
     push dword [source_file_out]
     call [fprintf]
     add esp,4*3
   
    push dword [source_file_in]
    call [fclose]
    add esp,4
    
    push dword [source_file_out]
    call [fclose]
    add esp,4
    
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program