.cpu cortex-m0
.align 1
.text
.global print_asciz


print_asciz:
    PUSH {R5, LR}
    MOV R5, R0
    
loop:
    LDRB R0, [R5]
    CMP R0, #0
    BEQ done
    BL convert_char
    BL uart_put_char
    ADD R5, R5, #1
    B loop
    
done:
    POP {R5, PC}