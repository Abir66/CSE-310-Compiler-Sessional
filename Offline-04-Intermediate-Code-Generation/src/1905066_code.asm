;-------
;   
;-------
.MODEL SMALL
.STACK 1000H
.Data
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
; ------------------ Line 4 ------------------
	SUB SP, 2
	SUB SP, 6
L0:
; ------------------ Line 5 ------------------
	PUSH 0
	POP AX
	SHL AX, 1
	LEA BX, [BP-4]
	SUB BX, AX
	PUSH BX
	PUSH 5
	POP AX
	POP BX
	MOV [BX], AX
	PUSH AX
	POP AX
L1:
; ------------------ Line 6 ------------------
	PUSH 2
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
L2:
; ------------------ Line 7 ------------------
	PUSH 0
	POP AX
	SHL AX, 1
	LEA BX, [BP-4]
	SUB BX, AX
	PUSH BX
	POP BX
	MOV AX, [BX]
	PUSH AX
	PUSH 2
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	MOV AX, [BP-2]
	PUSH AX
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	PUSH 1
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP AX
	CALL print_output
	CALL new_line
L3:
; ------------------ Line 8 ------------------
	MOV AX, [BP-2]
	PUSH AX
	POP AX
	CALL print_output
	CALL new_line
L4:
; ------------------ Line 9 ------------------
	PUSH 0
	POP AX
	SHL AX, 1
	LEA BX, [BP-4]
	SUB BX, AX
	PUSH BX
	POP BX
	MOV AX, [BX]
	PUSH AX
	POP AX
	CALL print_output
	CALL new_line
L5:
; ------------------ Line 10 ------------------
	PUSH 5
	PUSH 6
	POP BX
	POP AX
	CMP AX, BX
	JG L7
	JMP L6
L6:
	PUSH 0
	POP AX
	SHL AX, 1
	LEA BX, [BP-4]
	SUB BX, AX
	PUSH BX
	POP BX
	MOV AX, [BX]
	PUSH AX
	PUSH 5
	POP BX
	POP AX
	CMP AX, BX
	JE L7
	JMP L8
	PUSH AX
L7:
	PUSH 1
	JMP L9
L8:
	PUSH 0
L9:
	POP AX
	CALL print_output
	CALL new_line
L10:
; ------------------ Line 11 ------------------
	PUSH 3
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
L11:
; ------------------ Line 12 ------------------
	MOV AX, [BP-2]
	PUSH AX
	PUSH 3
	POP BX
	POP AX
	CMP AX, BX
	JG L12
	JMP L13
L12:
	PUSH 1
	JMP L14
L13:
	PUSH 0
L14:
	POP AX
	CALL print_output
	CALL new_line
L15:
; ------------------ Line 13 ------------------
	PUSH 0
	POP AX
	JMP L16
L16:
	ADD SP, 8
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
END main
