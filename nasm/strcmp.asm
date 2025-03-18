BITS 64
SECTION .text
GLOBAL strcmp

strcmp:
    push RBP
    mov RBP, RSP

    xor RCX, RCX
    xor RAX, RAX

while_same:
    mov R8B, BYTE [RDI + RCX]
    cmp R8B, 0
    je do_cmp
    cmp BYTE [RSI + RCX], 0
    je do_cmp
    cmp BYTE [RSI + RCX], R8B
    jne do_cmp
    inc RCX
    jmp while_same

do_cmp:
    movzx RAX, R8B
    movzx R8, BYTE [RSI + RCX]
    sub RAX, R8

    mov RSP, RBP
    pop RBP
    ret
