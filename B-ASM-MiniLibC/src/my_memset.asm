; memset : void *memset(void *s, int c, size_t n);
; The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
BITS 64

global memset:

SECTION .text

memset:
    xor     rax, rax
    xor     rcx, rcx
    jmp     fill

fill:
    cmp     rdx, 0
    je      end
    mov     BYTE [rdi + rcx], sil
    dec     rdx
    inc     rcx
    jmp     fill

end:
    mov     rax, rdi
    ret