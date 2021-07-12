; memcpy : void *memcpy(void *dest, const void *src, size_t n);
; The memcpy() function copies n bytes from memory area src to memory area dest. The memory areas must not overlap.
BITS 64

global memcpy:

SECTION .text
	
memcpy:
    xor     rax, rax
    xor     rbx, rbx
    jmp     copy

copy:
    cmp     rbx, rdx
    je      end
    mov     r10b, BYTE [rsi + rbx]
    mov     [rdi + rbx], r10b
    inc     rbx
    jmp     copy

end:
    mov     rax, rdi
    ret