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

; Se citeste o propozitie de la tastatura. Sa se inverseze fiecare cuvant si sa se afiseze pe ecran.

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
    
        push dword 0
        call [exit]