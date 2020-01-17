.cpu cortex-m0
tekstje: 
    .asciz "GegRoet"
.align 1
.text
.global application
.global tekstje


application:
    LDR R0, =tekstje
    BL print_asciz
    

done:
    MOV PC, LR
