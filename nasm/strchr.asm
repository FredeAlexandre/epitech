BITS 64
SECTION .text
GLOBAL strchr

strchr:
    push RBP
    mov RBP, RSP

    xor RAX, RAX
begin:
    cmp BYTE [RDI + RAX], SIL
    je found
    cmp BYTE [RDI + RAX], 0
    je not_found
    inc RAX
    jmp begin

not_found:
    mov RAX, 0
    jmp end
found:
    add RAX, RDI
end:
    mov RSP, RBP
    pop RBP
    ret
