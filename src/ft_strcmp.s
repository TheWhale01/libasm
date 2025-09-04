section .text
    global ft_strcmp

ft_strcmp:
    xor rax, rax
    xor rcx, rcx
    call loop

loop:
    mov al, byte [rdi + rcx]
    mov bl, byte [rsi + rcx]
    cmp al, 0x0
    je end
    cmp bl, 0x0
    je end
    cmp al, bl
    jne end
    inc rcx
    jmp loop

end:
    sub al, bl
    ret
