bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

; s1 - sir de quads in mem => s2 = high doublewords cu prop ca high word > low word in interpr cu semn
; vocale(s2) => nr de doublewords cu prop ca the high byte of the low word = ascii code of a vowel
; prog afiseaza nr returnat de functia vocale

segment data use32 class=data
    ; doubleword = 4 b => 8 hexa 
    ; quad : 16 hexa
    s1 dq 6500610000000060h, 7900650000000060h, 7900750000000060h, 45489512654780h, 987932145124689h, 65464896689787h
    len equ ($-s1)/8 ; len = the number of quadwords in s1
    s2 times len dd 0
    format db "%d", 0
    vowels db "aeiouAEIOU", 0
    count dd 0
    
segment code use32 class=code

; v1
; vocale:
    ; ; cum stiu cate elemente are sirul?
    ; ; [esp] - the return address
    ; ; [esp + 4] = the address of the string passed as a parameter to the function (s2)
    ; mov esi, [esp + 4]
    ; mov ecx, [count] ;parse the string of doublewords in a loop with [count] iterations, ([count] stores the length of the string)
    ; mov edx, 0
    ; .repeat1:
        ; lodsw ; ax = the low word
        ; ; the high byte of ax is ah
        ; ; count in edx the number of high bytes that represent the ascii code of a vowel
        ; mov al, "a"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "e"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "i"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "o"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "u"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "A"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "I"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "E"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "O"
        ; cmp ah, al
        ; je .is_vowel
        ; mov al, "U"
        ; cmp ah, al
        ; je .is_vowel
        ; jmp .not_vowel
        ; .is_vowel:
            ; inc edx
        ; .not_vowel:
        ; lodsw ; load into eax the high word of the current doubleword to ensure esi now stores the address of the next doubleword
        
    ; loop .repeat1 ; the loop ends when ECX=0 i.e the end of the string was reached
    ; mov eax, edx ; the function returns the number of doubleword with the required property in eax
    ; ret

; v2
vocale2:
       ; [esp] - the return address
    ; [esp + 4] = the address of the string passed as a parameter to the function (s2)
    mov esi, [esp + 4]
    mov ecx, [count] ;parse the string of doublewords in a loop with [count] iterations, ([count] stores the length of the string)
    mov edx, 0
    .repeat1:
        lodsw ; ax = the low word
        ; the high byte of ax is ah
        ; count in edx the number of high bytes that represent the ascii code of a vowel
        push ecx
        push esi
        mov esi, vowels
        mov ecx, 10 ; 10 vowels
        .repeat2:
            lodsb ; al = the current vowel
            cmp ah, al
            je .is_vowel
        loop .repeat2
        jmp .not_vowel
        .is_vowel:
            inc edx
        .not_vowel:
        pop esi
        pop ecx
        lodsw ; load into eax the high word of the current doubleword to ensure esi now stores the address of the next doubleword
    loop .repeat1 ; the loop ends when ECX=0 i.e the end of the string was reached
    mov eax, edx ; the function returns the number of doubleword with the required property in eax
    ret
    
start:
    mov esi, s1 ; esi = the address of the string s1
    mov edi, s2 ; edi = the address of the destination string s2
    cld ; clear direction flag to parse the string from left to right (DF=0)
    mov ecx, len ; parse the elements of the string in a loop with len iterations
    repeat: 
        lodsd ; eax = the low doubleword of the current quadword in the string
        lodsd ; eax = the high doubleword of the current quadword in the string
        ; compare the high word of eax with the low word of eax in signed interpretation
        mov ebx, eax ; save the value of eax in ebx
        mov dx, ax ; dx = the low word of eax (of the high double word)
        shr eax, 16 ; shift the bits in eax 16 positions to the right => ax now stores the high word
        cmp ax, dx
        jle not_greater ;check if high word > low word
            mov eax, ebx ;restore the value of eax
            stosd ;store its value in the destination string (the word at the address ES:EDI = EAX)
            inc dword [count]
        not_greater:
    loop repeat ; the loop stops when ECX=0
    ; determine the number of doublewords in s2 with the given property
    push dword s2
    call vocale2
    add esp, 4*1
    
    ; display the result returned in eax
    ; printf(format, value1, value2, ...)
    push eax
    push dword format
    call [printf]
    add esp, 4*2 ; clean the stack
    
    push dword 0
    call [exit]