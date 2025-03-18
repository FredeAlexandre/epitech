BITS 64
SECTION .text
GLOBAL strstr


strstr:
    push RBP
    mov RBP, RSP

    xor RCX, RCX

while_phrase_not_over:
    cmp BYTE [RDI], 0
    je not_found
target_loop:
    mov R8B, BYTE [RSI + RCX]
    cmp R8B, 0
    je found
    cmp BYTE [RDI + RCX], R8B
    jne continue_parsing
    inc RCX
    jmp target_loop

continue_parsing:
    inc RDI
    xor RCX, RCX
    jmp while_phrase_not_over

found:
    mov RAX, RDI
    jmp end
not_found:
    mov RAX, RAX
end:
    mov RSP, RBP
    pop RBP
    ret
