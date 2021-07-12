; strcasecmp : int strcasecmp(const char *s1, const char *s2);
BITS 64

global strcasecmp:

SECTION .text

strcasecmp:
    mov     r10b, BYTE [rdi]
    mov     r11b, BYTE [rsi]
    jmp     loop

loop:
    cmp     r10b, 0
    je      end
    cmp     r11b, 0
    je      end
    cmp     r10b, 97
    jge     check_lower_10

end_loop:
    cmp     r11b, 97
    jge     check_lower_11

compare:
    cmp     r10b, r11b
    jne     end
    add     rdi, 1
    add     rsi, 1
    jmp     strcasecmp

convert_11:
    sub     r11b, 32
    jmp     loop

check_lower_11:
    cmp     r11b, 122
    jle     convert_11

convert_10:
    sub     r10b, 32
    jmp     end_loop

check_lower_10:
    cmp     r10b, 122
    jle     convert_10

end:
    xor     RAX, RAX
    xor     RBX, RBX
    movzx   RAX, BYTE [RDI]
    movzx   RBX, BYTE [RSI]
    sub     RAX, RBX
    ret
