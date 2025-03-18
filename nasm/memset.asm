BITS 64
SECTION .text
GLOBAL memset

memset:
    push RBP
    mov RBP, RSP

    mov RAX, RDI
    xor RCX, RCX
begin:
    cmp RCX, RDX
    je end
    mov [RDI + RCX], SI
    inc RCX
    jmp begin
end:
    mov RSP, RBP
    pop RBP
    ret
