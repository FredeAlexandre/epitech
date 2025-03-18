BITS 64
SECTION .text
GLOBAL strcspn

strcspn:
    push RBP
    mov RBP, RSP
    xor RCX, RCX
    mov R9, RDI
while_not_found:
    cmp BYTE [RDI], 0
    je found
searching:
    mov R8B, BYTE [RSI + RCX]
    cmp R8B, BYTE [RDI]
    je found
    cmp R8B, 0
    je reset
    inc RCX
    jmp searching
reset:
    inc RDI
    xor RCX, RCX
    jmp while_not_found

found:
    mov RAX, RDI
    sub RAX, R9
end:
    mov RSP, RBP
    pop RBP
    ret
