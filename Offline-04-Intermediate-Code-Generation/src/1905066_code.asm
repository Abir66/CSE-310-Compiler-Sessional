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
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
; ------------------ Line 3 ------------------
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L0:
; ------------------ Line 5 ------------------
	LEA SI, STRING
	MOV [SI+0], 'E'
	MOV [SI+1], 'n'
	MOV [SI+2], 't'
	MOV [SI+3], 'e'
	MOV [SI+4], 'r'
	MOV [SI+5], ' '
	MOV [SI+6], 'n'
	MOV [SI+7], 'u'
	MOV [SI+8], 'm'
	MOV [SI+9], 'b'
	MOV [SI+10], 'e'
	MOV [SI+11], 'r'
	MOV [SI+12], ' '
	MOV [SI+13], 'o'
	MOV [SI+14], 'f'
	MOV [SI+15], ' '
	MOV [SI+16], 'r'
	MOV [SI+17], 'o'
	MOV [SI+18], 'w'
	MOV [SI+19], 's'
	MOV [SI+20], ' '
	MOV [SI+21], ':'
	MOV [SI+22], ' '
	MOV [SI+23], '$'
	LEA DX, STRING
	MOV AH, 09H
	INT 21H
L1:
; ------------------ Line 6 ------------------
	CALL int_intput
	MOV AX, INT_
	MOV [BP-2], AX
L2:
; ------------------ Line 8 ------------------
	PUSH 1
	POP AX
	MOV [BP-6], AX
	PUSH AX
	POP AX
L3:
	MOV AX, [BP-6]
	PUSH AX
	MOV AX, [BP-2]
	PUSH AX
	POP BX
	POP AX
	CMP AX, BX
	JLE L5
	JMP L14
	POP AX
L4:
	MOV AX, [BP-6]
	PUSH AX
	INC AX
	MOV [BP-6], AX
	POP AX
	JMP L3
L5:
; ------------------ Line 10 ------------------
	PUSH 1
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L6:
	MOV AX, [BP-4]
	PUSH AX
	MOV AX, [BP-2]
	PUSH AX
	MOV AX, [BP-6]
	PUSH AX
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP BX
	POP AX
	CMP AX, BX
	JLE L8
	JMP L9
	POP AX
L7:
	MOV AX, [BP-4]
	PUSH AX
	INC AX
	MOV [BP-4], AX
	POP AX
	JMP L6
L8:
; ------------------ Line 11 ------------------
	LEA SI, STRING
	MOV [SI+0], ' '
	MOV [SI+1], '$'
	LEA DX, STRING
	MOV AH, 09H
	INT 21H
	JMP L7
L9:
; ------------------ Line 14 ------------------
	PUSH 1
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L10:
	MOV AX, [BP-4]
	PUSH AX
	PUSH 2
	MOV AX, [BP-6]
	PUSH AX
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	PUSH 1
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP BX
	POP AX
	CMP AX, BX
	JLE L12
	JMP L13
	POP AX
L11:
	MOV AX, [BP-4]
	PUSH AX
	INC AX
	MOV [BP-4], AX
	POP AX
	JMP L10
L12:
; ------------------ Line 15 ------------------
	LEA SI, STRING
	MOV [SI+0], '*'
	MOV [SI+1], '$'
	LEA DX, STRING
	MOV AH, 09H
	INT 21H
	JMP L11
L13:
; ------------------ Line 18 ------------------
	CALL new_line
	JMP L4
L14:
; ------------------ Line 22 ------------------
	PUSH 0
	POP AX
	JMP L15
L15:
	ADD SP, 6
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
