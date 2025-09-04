section .text
    global ft_strlen

ft_strlen:
    xor rax, rax
    cmp rdi, 0x0
    je end
    call loop

loop:
    cmp byte [rdi + rax], 0x0
    je end; if true return
    inc rax
    jmp loop

end:
    ret
