BITS 64
SECTION .text
GLOBAL strcasecmp

check_case:
    push RBP
    mov RBP, RSP
    cmp RSI, RDI
    je check_is_same
    cmp RDI, 97
    jl skip_rdi_upper
    sub RDI, 32
skip_rdi_upper:
    cmp RSI, 97
    jl skip_rsi_upper
    sub RSI, 32
skip_rsi_upper:
    cmp RSI, RDI
    je check_is_same

    xor RAX, RAX
    jmp check_case_end
check_is_same:
    mov RAX, 1
check_case_end:
    mov RSP, RBP
    pop RBP
    ret

strcasecmp:
    push RBP
    mov RBP, RSP

    xor RCX, RCX
    xor RAX, RAX
    mov R8, RDI
    mov R9, RSI
while_same:
    movzx RDI, BYTE [R8 + RCX]
    movzx RSI, BYTE [R9 + RCX]
    cmp RDI, 0
    je do_cmp
    cmp RSI, 0
    je do_cmp
    call check_case
    cmp RAX, 0
    jne do_cmp
    inc RCX
    jmp while_same

do_cmp:
    mov RAX, RDI
    sub RAX, RSI

    mov RSP, RBP
    pop RBP
    ret
