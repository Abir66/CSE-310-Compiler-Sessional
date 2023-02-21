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
	MOV AX, 0
	SHL AX, 1
	LEA BX, [BP-4]
	SUB BX, AX
	PUSH BX
	MOV AX, 5
	POP BX
	MOV [BX], AX
L1:
; ------------------ Line 6 ------------------
	MOV AX, 2
	MOV [BP-2], AX
L2:
; ------------------ Line 7 ------------------
	MOV AX, 0
	SHL AX, 1
	LEA BX, [BP-4]
	SUB BX, AX
	MOV AX, [BX]
	PUSH AX
	MOV BX, 2
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	MOV AX, [BP-2]
	MOV BX, AX
	POP AX
	ADD AX, BX
	PUSH AX
	MOV BX, 1
	POP AX
	SUB AX, BX
	CALL print_output
	CALL new_line
L3:
; ------------------ Line 8 ------------------
	MOV AX, [BP-2]
	CALL print_output
	CALL new_line
L4:
; ------------------ Line 9 ------------------
	MOV AX, 0
	SHL AX, 1
	LEA BX, [BP-4]
	SUB BX, AX
	MOV AX, [BX]
	CALL print_output
	CALL new_line
L5:
; ------------------ Line 10 ------------------
	PUSH 5
	MOV BX, 6
	POP AX
	CMP AX, BX
	JG L7
	JMP L6
L6:
	MOV AX, 0
	SHL AX, 1
	LEA BX, [BP-4]
	SUB BX, AX
	MOV AX, [BX]
	PUSH AX
	MOV BX, 5
	POP AX
	CMP AX, BX
	JE L7
	JMP L8
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
	MOV AX, 3
	MOV [BP-2], AX
L11:
; ------------------ Line 12 ------------------
	MOV AX, [BP-2]
	PUSH AX
	MOV BX, 3
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
	MOV AX, 0
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
