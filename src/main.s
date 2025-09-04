extern      ft_strlen
extern      ft_write
extern      ft_strcpy
extern      ft_strcmp

section     .rodata
    hello_str   db "b", 0
    bonj_str   db "a", 0

section     .bss
    dest_str    resb 100

section     .text
    global  _start

_start:
    ; ft_strcpy
    mov     rdi, dest_str
    mov     rsi, hello_str
    call    ft_strcpy

    ; ft_write
    call    ft_strlen
    mov     rdi, 1 ; stdout
    mov     rsi, dest_str
    mov     rdx, rax
    call    ft_write

    ; ft_strcmp
    mov     rdi, hello_str
    call    ft_strcmp

    ; exit
    mov     rdi, rax
    mov     rax, 60 ; sys_exit
    syscall
