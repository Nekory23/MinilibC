; strpbrk : char *strpbrk(const char *str, const char *ok);
BITS 64

global strpbrk:

SECTION .text

strpbrk:
    xor     rax, rax
    jmp     loop

increment:
    inc     rdi
    jmp     loop

compare:
    mov     r11b, BYTE [rsi + rbx]
    cmp     r11b, 0
    je      increment
    cmp     r10b, r11b
    je      end
    inc     rbx
    jmp     compare

loop:
    mov     r10b, BYTE [rdi]
    cmp     r10b, 0
    je      end_null
    xor     rbx, rbx
    jmp     compare

end_null:
    ret

end:
    mov     rax, rdi
    ret