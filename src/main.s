extern      ft_strlen
extern      ft_write
extern      ft_strcpy

section     .rodata
    hello_str   db "allo JULO !", 0x0A, 0

section     .bss
    dest_str    resb 100

section     .text
    global  _start

_start:
    mov     rdi, dest_str
    mov     rsi, hello_str
    call    ft_strcpy
    call    ft_strlen
    mov     rdi, 1 ; stdout
    mov     rsi, dest_str
    mov     rdx, rax
    call    ft_write

    mov     rax, 60 ; sys_exit
    xor     rdi, rdi
    syscall
