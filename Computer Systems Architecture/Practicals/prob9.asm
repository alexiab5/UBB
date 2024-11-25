; De la tastatura se citeste un nume de fisier input. Se creaza un alt fisier de output in care se pune continutul fisierului de input cu toate caracterele mici schimbate cu codul lor ascii.

bits 32

global start

extern exit, scanf, fopen, fclose, fprintf, fread, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    access_mode1 dd "r", 0
    access_mode2 dd "w", 0
    file_name_in times 20 db 0
    file_descriptor_in dd 0
    file_name_out db "output.txt", 0
    file_descriptor_out dd 0
    message1 db "Enter the name of the input file: ", 0
    message2 db "The input file was opened successfully!", 10, 0
    message3 db "The output file was opened successfully!", 10, 0
    format1 db "%s", 0
    format2 db "%c", 0
    format3 db "%d ", 0
    string times 100 db 0
    

segment code use32 class=code
    start:
    
        push dword message1
        call [printf]
        add esp, 4
        
        push dword file_name_in
        push dword format1
        call [scanf]
        add esp, 4*2

        ; open the input file
        push dword access_mode1
        push dword file_name_in
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor_in], eax
        
        cmp eax, 0
        je end
        
        push dword message2
        call [printf]
        add esp, 4
        
        ; open the output file
        push dword access_mode2
        push dword file_name_out
        call [fopen]
        add esp, 4*2
        
        mov [file_descriptor_out], eax
        
        cmp eax, 0
        je end
        
        push dword message3
        call [printf]
        add esp, 4
        
        ; read the contents of the input file in stages and write in the output file the result
        reading:
            ; fread(str, size, count, fd)
            push dword [file_descriptor_in]
            push dword 100 ; count
            push dword 1 ; size
            push dword string
            call [fread]
            add esp, 4*4
            
            cmp eax, 0
            je finished_reading
            
            mov esi, string
            parse_string:
                cmp byte [esi], 0
                je end_of_string
                
                mov ebx, 0
                mov bl, [esi]
                inc esi
                cmp bl, 'a'
                jb not_lowercase
                    cmp bl, 'z'
                    ja not_lowercase
                    
                    ; if bl is lowercase, print its ASCII code to the output file
                    push ebx
                    push dword format3
                    push dword [file_descriptor_out]
                    call [fprintf]
                    add esp, 4*3
                    
                    jmp parse_string
                not_lowercase:
                
                ; else, print the character as it is
                push ebx
                push dword format2
                push dword [file_descriptor_out]
                call [fprintf]
                add esp, 4*3
                
                jmp parse_string
            end_of_string:
            jmp reading
        
    finished_reading:
        push dword [file_descriptor_in]
        call [fclose]
        add esp, 4
        
        push dword [file_descriptor_out]
        call [fclose]
        add esp, 4
        
    end:
        
        push dword 0
        call [exit]
        
        
