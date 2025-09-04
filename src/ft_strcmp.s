section .text
    global ft_strcmp

ft_strcmp:
    xor rax, rax
    xor rcx, rcx
    call loop

loop:
    mov r8b, byte [rdi + rcx]
    mov r9b, byte [rsi + rcx]
    cmp r8b, 0x0
    je end
    cmp r9b, 0x0
    je end
    cmp r8b, r9b
    jne end
    inc rcx
    jmp loop

end:
    movzx rax, r8b
    movzx r9, r9b
    sub rax, r9
    ret
