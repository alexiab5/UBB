bits 32

global start

extern exit, printf, scanf, fprintf, fscanf, fread, fopen, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fscanf msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

; Se citeste o propozitie de la tastatura. Sa se numere literele din fiecare cuvant si sa se afiseze aceste numere pe ecran.

segment data use32 class=data

    current_word times 50 db 0
    count dd 0
    count_words dd 0
    results_array times 50 dd 0
    message1 db "Enter the sentence: ", 0
    reading_format db "%s", 0
    printing_format db "%d ", 0
    file_descriptor dd -1

segment code use32 class=code
    
    start:
        
        push message1
        call [printf]
        add esp, 4
        
        mov edi, results_array
        read_words:
            push current_word
            push reading_format
            call [scanf]
            add esp, 4*2
            
            ; count the letters in the word
            mov dword [count], 0 
            inc dword [count_words]            
            mov esi, current_word
            repeat:
                lodsb
                cmp al, "A"
                jb not_letter
                    cmp al, "Z"
                    ja upper
                    ; uppercase letter ("A" <= AL <= "Z")
                    inc dword [count]
                    jmp not_letter
                    upper:
                        cmp al, "a"
                        jb not_letter
                        cmp al, "z"
                        ja not_letter
                        ; lowercase letter ("a" <= AL <= "z")
                        inc dword [count]  
                not_letter:
                ; check if the current word ends with "." => the end of the sentence
                
                cmp al, "." 
                je end_of_sentence
                cmp al, 0
                jne repeat
                
            mov ebx, [count]
            mov [edi], ebx
            add edi, 4
            
            jmp read_words
    end_of_sentence:
    
    ; letter count for the last word
    mov ebx, [count]
    mov [edi], ebx
    
    mov esi, results_array  
    printing:
        push dword [esi]
        push dword printing_format
        call [printf]
        add esp, 4*2
        
        add esi, 4
        dec dword [count_words]
        cmp dword [count_words], 0
        jne printing
        
        push dword 0
        call [exit] 