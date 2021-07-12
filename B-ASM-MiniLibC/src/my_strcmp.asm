; strcmp : int strcmp(const char *s1, const char *s2);
BITS 64

global strcmp:

SECTION .text

strcmp:
    cmp     BYTE [rdi], 0x00
    je      end
    cmp     BYTE [rsi], 0x00
    je      end
    mov     r10b, BYTE [rsi]
    cmp     BYTE [rdi], r10b
    jne     end
    add     rdi, 1
    add     rsi, 1
    jmp     strcmp

end:
    xor     rax, rax
    xor     rbx, rbx
    movzx   rax, BYTE [rdi]
    movzx   rbx, BYTE [rsi]
    sub     rax, rbx
    ret