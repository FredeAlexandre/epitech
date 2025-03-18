BITS 64
SECTION .text
GLOBAL strlen

strlen:
    push RBP
    mov RBP, RSP
    xor RAX, RAX
begin:
    cmp BYTE [RDI + RAX], 0
    je end
    inc RAX
    jmp begin
end:
    mov RSP, RBP
    pop RBP
    ret
