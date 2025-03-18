BITS 64
SECTION .text
GLOBAL strpbrk

strpbrk:
    push RBP
    mov RBP, RSP
    xor RCX, RCX
while_not_found:
    cmp BYTE [RDI], 0
    je not_found
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
    jmp end
not_found:
    xor RAX, RAX
end:
    mov RSP, RBP
    pop RBP
    ret
