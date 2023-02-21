
.MODEL SMALL
.STACK 1000H
.Data
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
	INT_ DW 0
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
    PUSH BP
	MOV BP, SP

    call int_intput

    POP BP
	MOV AX,4CH
	INT 21H
main ENDP

int_intput PROC
    PUSH BP
    MOV BP, SP
    SUB SP, 2

    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX

    MOV BX, 0
    MOV AX, 0
    MOV CX, 0
    MOV DX, 0 
    MOV [BP-2], 0

L_INPUT_LOOP:
    MOV AH, 01H
    INT 21H

    ; check if new_line
    CMP AL, CR
    JE L_NEW_LINE
    CMP AL, LF
    JE L_NEW_LINE

    ; check if minus sign
    CMP AL, '-'
    JNE L_MINUS_SIGN

    MOV [BP-2], 1
    JMP L_INPUT_LOOP

L_MINUS_SIGN:

    ; character to digit
    SUB AL, '0'
    MOV AH, 0
    MOV CX , AX

    ; BX = BX * 10 + AX
    MOV AX, 10
    MUL BX
    ADD AX, CX
    MOV BX, AX
    JMP L_INPUT_LOOP
    
L_NEW_LINE:

    ; check if minus sign
    CMP [BP-2], 1
    JNE L_ALL_DONE
    ; BX = -BX
    NEG BX

L_ALL_DONE:

    MOV INT_ , BX

    POP DX
    POP CX
    POP BX
    POP AX

    ADD SP, 2
    POP BP
    RET
int_intput ENDP


END main