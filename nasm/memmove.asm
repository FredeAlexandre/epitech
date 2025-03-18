BITS 64
SECTION .text
GLOBAL memmove

memmove:
    push RBP
    mov RBP, RSP

    mov RAX, RDI
    xor RCX, RCX
begin:
    cmp RCX, RDX
    je end
    mov R8W, [RSI + RCX]
    mov [RDI + RCX], R8W
    inc RCX
    jmp begin
end:
    mov RSP, RBP
    pop RBP
    ret
