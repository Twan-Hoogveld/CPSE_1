.cpu cortex-m0
.align 1
.bss
    buffer: .fill 100

.text
.global Text_Decoder


Text_Decoder:
    PUSH {R5, R6, R7, LR}
    LDR R1, =buffer
    MOV R5, R0 
    MOV R4, #100

    
loop:
    LDRB R0, [R5]
    CMP R0, #64
    BEQ Decoder
    CMP R0, #0
    BEQ done
    BL BufferShift
    ADD R5, R5, #1
    B loop

 
Decoder:

    LDRB R7, [R5, #1]
    LDRB R6, [R5, #2]
    SUB R7, #48
    SUB R6, #48
    B Decoderloop
    

Decoderloop:
    LDRB R0, [R1, R7]
    BL BufferShift
    SUB R6, R6, #1
    CMP R6, #0
    BEQ DecoderEnd
    B Decoderloop
    
DecoderEnd:
    ADD R5, R5, #3
    B loop
    
   
   
BufferShift:
    PUSH { LR }
BufferLoop:
    
    SUB R4, R4, #1
    LDRB R3, [R1, R4]
    ADD R4, R4, #1
    STRB R3, [R1, R4]
    SUB R4, R4, #1
    CMP R4, #0
    BEQ BufferStore
    B BufferLoop
    
BufferStore:
    STRB R0, [R1, #0]
    PUSH { R0, R1, R2, R3}
    BL print_text
    MOV R4, #100
    POP {R0, R1, R2, R3, PC}
    

   
done:
    POP {R5, R6, R7, PC}