bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions


;Given a character string S, obtain the string D containing all special characters (!@#$%^&*) of the string S.
segment data use32 class=data

    s db '+', '4', '2', 'a', '@', '3', '$', '*' ; declare the string of bytes
    l equ $-s ; compute the length of the string (l = number of bytes in s)
	d times l db 0 ; reserve l bytes for the destination string

segment code use32 class=code
    start:
        mov ecx, l ; we put the length l in ecx in order to make the loop
        mov esi, 0
        mov edi, 0     
        
        repeat:
            mov al, [s + esi] ; al = current character in s
            mov ah, 21h 
            
            cmp al, 40h ; check if character is '@'
            jz is_special_char ; jump if is zero (ZF=1)
            
            cmp al, 5eh ; check if character is '^'
            jz is_special_char ; jump if is zero
            
            cmp ah, al
            ja not_special_char ; jump if above (CF=0 and ZF=0)
                mov ah, 2bh
                cmp al, ah
                ja not_special_char
                is_special_char:
                    mov [d + edi], al ; add current special character to d
                    inc edi
            not_special_char:
            inc esi ; increment counter
        loop repeat

        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
