section .text
    global ft_strcpy

ft_strcpy:
    xor rcx, rcx
    call loop

loop:
    cmp byte [rsi + rcx], 0x0
    je end
    mov r8b, byte [rsi + rcx]
    mov byte [rdi + rcx], r8b
    inc rcx
    jmp loop

end:
    mov byte [rdi + rcx], 0x0
    mov rax, rdi
    ret
