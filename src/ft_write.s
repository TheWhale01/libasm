extern ft_strlen

section .text
    global ft_write

ft_write:
    mov     rax, 1 ; sys_write
    syscall
    ; cmp rax, 0
    ; js error
    ret

; error:
;     call __errno_location
;     neg rax
;     mov [rax], eax
