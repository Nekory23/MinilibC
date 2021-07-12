; strcspn : size_t strcspn(const char *s, const char *reject);
BITS 64

global strcspn:

SECTION .text

strcspn:
    xor     rax, rax
    xor     rbx, rbx
    jmp     loop

increment:
    add     rbx, 1
    add     rdi, 1
    jmp     loop

check_non_authorized:
    mov     r11b, BYTE [rsi + rcx]
    cmp     r11b, 0
    je      increment
    cmp     r10b, r11b
    je      end
    inc     rcx
    jmp     check_non_authorized

loop:
    mov     r10b, BYTE [rdi]
    cmp     r10b, 0
    je      end
    xor     rcx, rcx
    jmp     check_non_authorized

end:
    add     rax, rbx
    ret