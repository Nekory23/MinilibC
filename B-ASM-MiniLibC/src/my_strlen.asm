; strlen : size_t strlen(const char *str);
global strlen:

SECTION .text

strlen:
    xor     rax, rax
    cmp     BYTE [rdi], 0x00
    je      return
    jne     .loop

.loop:
    add     rax, 1
    add     rdi, 1
    cmp     BYTE [rdi], 0x00
    je      return
    jne     .loop

return:
    ret