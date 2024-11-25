bits 32

global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll


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

start:
    
    push dword 0
    call [exit]