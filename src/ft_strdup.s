section .text
    global ft_strdup
    extern malloc
    extern ft_strlen
    extern ft_strcpy
    extern __errno_location

ft_strdup:
    push rdi
    call ft_strlen
    inc rax
    mov rdi, rax
    call malloc wrt ..plt
    cmp rax, 0
    je error
    mov rdi, rax
    pop rsi
    call ft_strcpy
    ret

error:
    neg rax
    mov rdi, rax
    call __errno_location wrt ..plt
    mov [rax], rdi
    mov rax, 0
    ret
