; strncmp : int strncmp(const char *s1, const char *s2, size_t n)
BITS 64

global strncmp:

SECTION .text

strncmp:
    cmp     rdx, 0
    je      end_null
    cmp     BYTE [rdi], 0x00
    je      end
    cmp     BYTE [rsi], 0x00
    je      end
    mov     r10b, BYTE [rsi]
    cmp     BYTE [rdi], r10b
    jne     end
    sub     rdx, 1
    cmp     rdx, 0
    je      end
    add     rdi, 1
    add     rsi, 1
    jmp     strncmp

end:
    xor     rax, rax
    xor     rbx, rbx
    movzx   rax, BYTE [rdi]
    movzx   rbx, BYTE [rsi]
    sub     rax, rbx
    ret

end_null:
    xor     RAX, RAX
    ret