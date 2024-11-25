bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

;An array of words is given. Write an asm program in order to obtain an array of doublewords, where each doubleword will contain each nibble unpacked ;on a byte (each nibble will be preceded by a 0 digit), arranged in an ascending order within the doubleword.

segment data use32 class=data
    arr dw 1432h, 8675h, 0ADBCh
    len equ ($-arr)/2 ; compute the length of the string
    aux dd 0
    nibble dd 0
    counter dd 0
    dest_arr times len dd 0 ; reserve len doublewords for the destination string and initialize them with 0
    nr1 db 0
    nr2 db 0
    
segment code use32 class=code
    start:
        mov esi, arr ; esi contains the offset of arr
        cld ; parse the string in ascending order
        mov ecx, len
        mov edi, dest_arr ; edi contains the offset of dest_arr
        ; create a new array where every doubleword contains the unpacked nibbles of the words in the original array
        repeat: ; loop to parse the array of words
            mov eax, 0
            lodsw ; ax = current word, esi = esi + 2
            mov dword [counter], 4
            mov dword [aux], 0
            unpack_nibbles: ; while to unpack the nibbles of the current word
            
                mov dword [nibble], 0000000Fh
                and [nibble], eax
                mov ebx, [nibble] ; ebx = 0000000dh, d = current hexa digit
                or [aux], ebx
                ror dword [aux], 8 ; last byte becomes first byte (make room for next digit)
                shr eax, 4 ; get rid of last hexadigit
                sub dword [counter], 1
                cmp dword [counter], 0
                jz end_of_word
            jmp unpack_nibbles
        end_of_word:
            mov eax, [aux]
            stosd ; put the current doubleword into the destination array, edi = edi + 4
        loop repeat ;if there are elements left in arr (ecx>0), resume the loop.
        
        ;arrange the nibbles in the doublewords of the new array in ascending order
        
        mov edx, dest_arr
        mov ecx, len
        repeat1: ; parse the doublewordds of destination array
            push ecx
            
            mov ecx, 4
            
            mov esi, edx
            ; sort the bytes of the current doubleword
            repeat2: ; for i
                push ecx
                
                mov edi, edx
                mov ecx, 4
                repeat3: ; for j
                    mov al, [esi]
                    mov ah, [edi]
                    cmp al, ah
                    jae noswitch
                        mov byte[esi], ah
                        mov byte[edi], al
                    noswitch:
                    inc edi
                loop repeat3
                
                inc esi
                pop ecx
            loop repeat2
            
            add edx, 4
            pop ecx
        loop repeat1
                
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
