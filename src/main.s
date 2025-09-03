extern      ft_strlen

section     .rodata
    hello   db "Bonjour les amies!", 10, 0

section     .bss
    len_hello   resd 1

section     .text
    global  _start

_start:
    mov     rdi, hello
    call    ft_strlen
    mov     rdx, rax

    mov     rax, 1 ; sys_write
    mov     rdi, 1 ; stdout
    mov     rsi, hello
    syscall

    mov     rax, 60 ; sys_exit
    mov     rdi, rdx ; choosing exit_code (slower)
    syscall
