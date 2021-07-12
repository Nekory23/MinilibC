; rindex : char *rindex(const char *str, int c);
BITS 64

global rindex:

SECTION .text

rindex:
    xor     rax, rax
    xor     rbx, rbx
    xor     rcx, rcx
    jmp     get_len

get_len:
    mov     r11b, BYTE [rdi + rcx]
    cmp     r11b, 0
    je      loop
    inc     rcx
    jmp     get_len

loop:
    mov     r10b, BYTE [rdi + rcx]
    cmp     rcx, 0
    je      last_check
    cmp     r10b, sil
    je      result
    sub     rcx, 1
    jmp     loop

last_check:
    cmp     r10b, sil
    je      end
    jmp     end_null

result:
    cmp     rbx, rcx
    je      end
    inc     rbx
    inc     rdi
    jmp     result

end_null:
    ret

end:
    mov     rax, rdi
    ret
