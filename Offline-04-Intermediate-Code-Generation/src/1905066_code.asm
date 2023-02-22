;-------
;   
;-------
.MODEL SMALL
.STACK 1000H
.Data
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
	STRING DB 100 DUP(?)
	INT_ DW 0
.CODE
f PROC
	PUSH BP
	MOV BP, SP
; ------------------ Line 2 ------------------
	MOV AX, [BP+4]
	PUSH AX
	POP AX
	CALL print_output
	CALL new_line
L0:
; ------------------ Line 3 ------------------
	MOV AX, [BP+4]
	PUSH AX
	PUSH 1
	POP BX
	POP AX
	CMP AX, BX
	JE L1
	JMP L2
L1:
; ------------------ Line 4 ------------------
	JMP L4
L2:
; ------------------ Line 6 ------------------
	MOV AX, [BP+4]
	PUSH AX
	DEC AX
	MOV [BP+4], AX
	POP AX
L3:
; ------------------ Line 7 ------------------
	MOV AX, [BP+4]
	PUSH AX
	CALL f
	PUSH 0
	POP AX
L4:
	ADD SP, 0
	POP BP
	RET 2
f ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
; ------------------ Line 11 ------------------
	PUSH 5
	CALL f
	PUSH 0
	POP AX
L5:
	ADD SP, 0
	POP BP
	MOV AX, 4CH
	INT 21H
main ENDP

new_line proc
    push ax
    push dx
    mov ah,2
    mov dl,cr
    int 21h
    mov ah,2
    mov dl,lf
    int 21h
    pop dx
    pop ax
    ret
new_line endp
print_output proc  ;print what is in ax
    push ax
    push bx
    push cx
    push dx
    push si
    lea si,number
    mov bx,10
    add si,4
    cmp ax,0
    jnge negate
    print:
    xor dx,dx
    div bx
    mov [si],dl
    add [si],'0'
    dec si
    cmp ax,0
    jne print
    inc si
    lea dx,si
    mov ah,9
    int 21h
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret
    negate:
    push ax
    mov ah,2
    mov dl,'-'
    int 21h
    pop ax
    neg ax
    jmp print
print_output endp

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
    
    call new_line
    
    POP DX
    POP CX
    POP BX
    POP AX

    ADD SP, 2
    POP BP
    RET
int_intput endp
END main
