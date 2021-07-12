; strchr : char *strchr(const char *str, int c);
BITS 64

global strchr:

SECTION .text

strchr:
    xor     rax, rax
    cmp     sil, 0
    je      null_char
    jmp     loop

loop:
    mov     r10b, BYTE [rdi]
    cmp     r10b, 0
    je      end_null
    cmp     r10b, sil
    je      end
    add     rdi, 1
    jmp     loop

null_char:
    cmp     BYTE [rdi], 0
    je      end
    inc     rdi
    jmp     null_char

end:
    mov     rax, rdi
    ret

end_null:
    ret
