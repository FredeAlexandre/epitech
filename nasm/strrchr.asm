BITS 64
SECTION .text
GLOBAL strrchr

strlen:
    push RBP
    mov RBP, RSP
    xor RAX, RAX
strlen_begin:
    cmp BYTE [RDI + RAX], 0
    je strlen_end
    inc RAX
    jmp strlen_begin
strlen_end:
    mov RSP, RBP
    pop RBP
    ret

strrchr:
    push RBP
    mov RBP, RSP

    call strlen
    cmp RAX, 0
    je not_found
    dec RAX

begin:
    cmp BYTE [RDI + RAX], SIL
    je found
    cmp RAX, 0
    je not_found
    dec RAX
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
