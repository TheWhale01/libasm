section .text
    global ft_strlen

ft_strlen:
    xor rcx, rcx
    cmp rdi, 0x0
    je end
    call loop

loop:
    cmp byte [rdi + rcx], 0x0
    je end; if true return
    inc rcx
    jmp loop

end:
    mov rax, rcx
    ret
