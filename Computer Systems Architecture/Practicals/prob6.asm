; Se citesc din fisierul numere.txt mai multe numere (pare si impare). Sa se creeze 2 siruri rezultat N si P astfel: N - doar numere impare si P - doar numere pare. Afisati cele 2 siruri rezultate pe ecran.

bits 32

global start

extern exit, fopen, fclose, fscanf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    access_mode db "r", 0
    file_name db "numere.txt", 0
    file_descriptor dd -1
    reading_format db "%d", 0
    printing_format db "%d ", 0
    print_ef db "%c", 0
    message1 db "The even numbers in the file are: ", 0
    message2 db "The odd numbers in the file are: ", 0
    number dd 0
    even_numbers_array times 50 db 0
    odd_numbers_array times 50 db 0
    even_numbers_count dd 0
    odd_number_count dd 0
    end_line db 0x0A, 0
    

segment code use32 class=code
    start:
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4*2
        
        cmp eax, 0
        je end
        
        mov [file_descriptor], eax
        mov esi, even_numbers_array
        mov edi, odd_numbers_array
        
        ; loop to read the numbers        
        read_numbers:
            push dword number
            push dword reading_format
            push dword [file_descriptor]
            call [fscanf]
            add esp, 4*3
            
            ; condition to end the loop : reached EOF
            cmp eax, 0
            jle finished_reading
            
            ; determine the parity of the current number
            mov eax, [number]
            cdq
            mov ecx, 2
            div ecx
            ; restore the number's value in eax
            mov eax, [number]
            cmp edx, 1
            je is_odd
               ; is even 
               mov [esi], eax
               add esi, 4
               inc dword [even_numbers_count]
               jmp is_even
            is_odd:
            mov [edi], eax
            add edi, 4
            inc dword [odd_number_count]
            is_even:
            
            jmp read_numbers
            
    finished_reading:
        
        ; print even numbers list
        push dword message1
        call [printf]
        add esp, 4
        
        mov esi, even_numbers_array
        print_even:
            push dword [esi]
            push dword printing_format
            call [printf]
            add esp, 4*2
            
            add esi, 4
            dec dword [even_numbers_count]
            cmp dword [even_numbers_count], 0
            jne print_even
            
        ; endline
        push dword [end_line]
        push dword print_ef
        call [printf]
        add esp, 4*2
       
        ; print odd numbers list
        push dword message2
        call [printf]
        add esp, 4
        
        mov esi, odd_numbers_array
        print_odd:
            push dword [esi]
            push dword printing_format
            call [printf]
            add esp, 4*2
            
            add esi, 4
            dec dword [odd_number_count]
            cmp dword [odd_number_count], 0
            jne print_odd
            
        ; close the file
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        
    end:
        
        push dword 0
        call [exit]