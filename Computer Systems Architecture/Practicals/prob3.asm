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

; Se citeste un cuvant de la tastatura. Sa se afiseze cuvantul inversat.

segment data use32 class=data

    reading_format db "%s", 0
    sentence times 50 db 0
    reversed_sentence times 50 db 0
    len dd 0
    message1 db "Enter the sentence: ", 0
    printing_format db "%s", 0
    file_descriptor dd -1

segment code use32 class=code
    
    start:
        push dword message1
        call [printf]
        add esp, 4
        
        push dword sentence
        push dword reading_format
        call [scanf]
        add esp, 4*2
        
        ; determine the length of the sentence / word
        mov esi, sentence
        det_length:
            mov al, [esi]
            cmp al, 0
            je finish1
            inc dword [len]
            inc esi
            jmp det_length
        finish1:
        
        ; determine the address of the end of the sentence / word
        mov eax, sentence
        mov ecx, [len]
        lea esi, [eax + ecx - 1]
        
        ; parse the sentence backwards and store the characters in the reversed_sentence/ word string
        mov ecx, [len]
        mov edi, reversed_sentence
        repeat:
            mov al, [esi]
            mov [edi], al
            inc edi
            dec esi
        loop repeat
        
        
        push dword reversed_sentence
        push dword printing_format
        call [printf]
        add esp, 4*3
        
        push dword 0
        call [exit]