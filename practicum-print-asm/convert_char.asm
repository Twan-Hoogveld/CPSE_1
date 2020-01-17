.cpu cortex-m0
.align 1
.text
.global convert_char

convert_char:
    PUSH {R6}
    MOV R6, R0
    CMP R6, #90
    BLE check_for_L_up
    CMP R6, #122
    BLE check_for_L_low
    POP {R6}
    MOV PC, LR
    
check_for_L_up:
    CMP R6, #65
    BGE to_lower
    POP {R6}
    MOV PC, LR
    
check_for_L_low:
    CMP R6, #97
    BGE to_upper
    POP {R6}
    MOV PC, LR
    
to_lower:
    ADD R6, #32 
    MOV R0, R6
    POP {R6}
    MOV PC, LR
    
to_upper:
    SUB R6, #32
    MOV R0, R6
    POP {R6}
    MOV PC, LR
    
