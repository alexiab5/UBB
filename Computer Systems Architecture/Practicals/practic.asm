; Fie un fisier -numele dat in segmentaul de date- ce contine mai multe note separate prin spatiu (notele sunt de la 1 la 10). Sa se citeasca aceste note, sa se calculeze suma si diferenta lor si sa se scrie la finalul fisierului./

bits 32 
global start        

extern exit, fopen, fclose, scanf, fprintf, printf, fscanf             
import exit msvcrt.dll    
import fopen msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll                          
import fprintf msvcrt.dll                          
import printf msvcrt.dll                          
import fscanf msvcrt.dll 

segment data use32 class=data
    access_mode db "a+", 0
    file_name db "OUTPUT.txt", 0
    file_descriptor dd -1
    sum dd 0
    difference dd 0
    number dd 0
    first_number db 0
    message db "success", 10, 0
    format db "%d", 0
    format2 db " %d", 0
    
segment code use32 class=code
    start:
        ; open the file
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor], eax
        
        ; check if the file was opened successfully
        cmp eax, 0
        je end
        
        push dword message
        call [printf]
        add esp, 4
        
        ; loop to read the numbers in the file
        read_numbers:
            ; fscanf(fd, format, var)
            push dword number
            push dword format
            push dword [file_descriptor]
            call [fscanf]
            add esp, 4*3
            
            ; check if EOF was reached
            cmp eax, 0
            jle finished_reading
            
            ; add the number to the sum
            mov eax, [number]
            clc
            add dword [sum], eax
            adc dword [sum], 0
            ; subtract the number from the difference
            cmp byte [first_number], 0
            jne not_first
                add dword [difference], eax
                inc byte [not_first]
                jmp first
        not_first:
            clc
            sub dword [difference], eax
            sbb dword [difference], 0
            
            ; push dword [number]
            ; push dword format2
            ; call [printf]
            ; add esp, 4*2
        first:
            jmp read_numbers
        
    finished_reading:
       
        ; write the sum at the end of the file
        ; fprintf(fd, format, var)
        push dword [sum]
        push dword format2
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4*3
        
        ; write the difference at the end of the file
        push dword [difference]
        push dword format2
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4*3
        
        ; close the file
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
    end:
        push dword 0      
        call [exit]       
