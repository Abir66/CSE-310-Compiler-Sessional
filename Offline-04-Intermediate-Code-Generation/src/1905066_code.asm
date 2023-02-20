;-------
;   
;-------
.MODEL SMALL
.STACK 1000H
.Data
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
	a DW 1 DUP (0000H)
	b DW 1 DUP (0000H)
	c DW 1 DUP (0000H)
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 20
	SUB SP, 2
L0:
	PUSH 7
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
L1:
	PUSH 6
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L2:
	MOV AX, [BP-2]
	PUSH AX
	MOV AX, [BP-4]
	PUSH AX
	POP BX
	POP AX
	CMP AX, BX
	JG L3
	JMP L4
L3:
	MOV AX, [BP-2]
	CALL print_output
	CALL new_line
	JMP L5
L4:
	MOV AX, [BP-4]
	CALL print_output
	CALL new_line
L5:
L6:
	MOV AX, [BP-4]
	PUSH AX
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JG L7
	JMP L9
L7:
	MOV AX, [BP-4]
	CALL print_output
	CALL new_line
L8:
	MOV AX, [BP-4]
	MOV AX, [BP-4]
	PUSH AX
	DEC AX
	MOV [BP-4], AX
	POP AX
	JMP L6
L9:
	PUSH 30
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L10:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
L11:
	PUSH 0
	POP AX
	ADD SP, 26
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
