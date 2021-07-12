; strstr : char *strstr(const char *haystack, const char *needle);
BITS 64

global strstr:

SECTION .text

strstr:
    xor     rax, rax
    cmp     BYTE [rsi], 0
    je      end
    jmp     loop

check_for_str:
    mov     r11b, BYTE [rsi + rbx]
    cmp     r11b, 0
    je      end
    cmp     r11b, BYTE [rdi + rcx]
    jne     increment
    inc     rbx
    inc     rcx
    jmp     check_for_str

increment:
    inc     rdi
    jmp     loop

loop:
    mov     r10b, BYTE [rdi]
    cmp     r10b, 0
    je      end_null
    xor     rbx, rbx
    xor     rcx, rcx
    cmp     r10b, BYTE [rsi]
    je      check_for_str
    add     rdi, 1
    jmp     loop
    
end_null:
    ret

end:
    mov     rax, rdi
    ret