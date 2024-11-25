bits 32

global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

; s = string of quadwords
; n = read from the kewboard, n between 1 and 6 else: exit
; s2 = bytes din n in n
; se afiseaza s2 sortat descrescator dupa nr de biti de 1
segment data use32 class=data
    s dq 1122334455667788h, 99AABBCCDDEEFF11h, 0FF00000000000055h, 0FFFEFFFFFFFFEFFFh, 450000AB000000ABh, 11113733355577ABh
    len equ ($-s)/8 ; len = the number of quadwords in s1
    len_bytes equ ($-s) ; len = the number of bytes in s1
    s2 times len_bytes db 0
    reading_format db "%d", 0
    printing_format db "%x ", 0
    message db "Enter a number between 1 and 6: ", 0
    n dd 0
    len2 db 0
    
segment code use32 class=code

count_number_of_1s:
    ; returns in eax the number of 1's in the binary representation of the number received as a parameter
    ; [esp + 4] = the number
    mov eax, 0
    mov ecx, [esp + 4]
    .count_1s:
        mov edx, ecx
        and edx, 1
        cmp edx, 1
        jne .not_1
            inc eax
        .not_1:
        shr ecx, 1
        cmp ecx, 0
        jne .count_1s
    ret

sort_string_bytes:
    ; sort the newly formed string of bytes in descending order by the number of bits 1
    ; [esp + 4] = the address of the string to be sorted
    mov esi, [esp + 4] ; esi = the address of the string
    push ebx ; create a new stack frame? the function should not change the value of ebx
    mov ecx, 0
    mov cl, [len2] ; ecx = the number of bytes in the string to be sorted
    ;the equivalent of the for i loop in C
    .sort_bytes_for_i:
        mov ebx, 0
        mov bl, [esi] ; bl = the current byte (v[i])
        push ecx ; save the value of ecx before calling the function to determine the number of bits 1 in bl
        
        push ebx
        call count_number_of_1s
        add esp, 4
        ; eax = the number of bits 1 in the current byte
        
        pop ecx
        
        inc esi ; esi now holds the address of the next byte in the string
        push ecx ; save the current value of ecx for later
        dec ecx ; we compare the byte at [esi] with all other bytes after it up until the end of the string, so with ecx-1 bytes
        cmp ecx, 0 ; !!!!!!!!!!!!!!!!!!!
        je .end_forj
        mov edi, esi
        mov edx, eax ; edx = the number of bits 1 in the byte at [esi - 1]
        .sort_bytes_for_j:
            mov ebx, 0
            mov bl, [edi] ; bl = v[j]

            push edx
            push ecx
            
            push ebx
            call count_number_of_1s
            add esp, 4
            
            pop ecx
            pop edx
            ; eax = the number of bits 1 in the current byte
            
            ; compare edx with eax 
            cmp edx, eax
            ja .no_switch
                ; swap the byte at [esi - 1] with the byte at [edi]
                mov bh, [esi - 1]
                mov [esi - 1], bl
                mov [edi], bh
                mov edx, eax ; !!!!!!!!!!!!!!!1
            .no_switch:
            inc edi
        loop .sort_bytes_for_j
        .end_forj:
        pop ecx
    loop .sort_bytes_for_i
    
    pop ebx
    ret
start:
    push dword message
    call [printf]
    add esp, 4
    
    push dword n
    push dword reading_format
    call [scanf]
    add esp, 4*2
    
    ; if the value read from the keyboard is not in [1,6], jump to the end of the program
    cmp dword [n], 1
    jb end1
    cmp dword [n], 6
    ja end1
    
    mov esi, s ; esi = the address of the string of quadwords
    mov edi, s2 ; the address of the destination string
    mov ebx, s
    add ebx, len_bytes ; ebx = the address of the end of the string
    loop1:
        movsb
        inc byte [len2]
        add esi, [n]
        dec esi
        cmp esi, ebx
        jb loop1 ; the loop ends when esi points to an address greater than the address of the end of the string
    ; sort the newly formed string of bytes in descending order by the number of bits 1
    
    
        
    ; mov ecx, 0
    ; mov cl, [len2]
    ; mov esi, s2
    ; repeat2:  
        ; mov eax, 0
        ; lodsb
        ; push ecx ; push the value of ecx on the stack bc printf changes the values of the registers
        
        ; push eax
        ; call count_number_of_1s
        ; add esp, 4
        
        ; push eax
        ; push dword printing_format
        ; call [printf]
        ; add esp, 4*2
        ; pop ecx
    ; loop repeat2
    
    
    push dword s2
    call sort_string_bytes
    add esp, 4
    
    ; loop to print the numbers in the sorted string of bytes in hexa
    mov ecx, 0
    mov cl, [len2]
    mov esi, s2
    
    repeat:  
        mov eax, 0
        lodsb
        push ecx ; push the value of ecx on the stack bc printf changes the values of the registers
        
        ; push eax
        ; call count_number_of_1s
        ; add esp, 4
        
        push eax
        push dword printing_format
        call [printf]
        add esp, 4*2
        pop ecx
    loop repeat
    
    mov ecx, 0
    mov cl, [len2]
    mov esi, s2
    repeat2:  
        mov eax, 0
        lodsb
        push ecx ; push the value of ecx on the stack bc printf changes the values of the registers
        
        push eax
        call count_number_of_1s
        add esp, 4
        
        push eax
        push dword printing_format
        call [printf]
        add esp, 4*2
        pop ecx
    loop repeat2
    
    end1:
    push dword 0
    call [exit]