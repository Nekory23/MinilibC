; memmove : void *memmove(void *dest, void *src, size_t n);
; The memmove() function copies n bytes from memory area src to memory area dest.
; The memory areas may overlap: copying takes place as though the bytes in src are first copied into a
; temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.
BITS 64

global memmove:

SECTION .text

memmove:
    xor     rax, rax
    xor     rcx, rcx
    cmp     rdx, 0
    je      end
    jmp     copy_temp

copy_temp:
    cmp     rcx, rdx
    je      copy
    movsx   rbx, BYTE [rsi + rcx]
    push    rbx
    inc     rcx
    jmp     copy_temp

copy:
    cmp     rcx, 0
    je      end
    pop     rbx
    dec     rcx
    mov     BYTE [rdi + rcx], bl
    jmp     copy

end:
    mov     rax, rdi
    ret