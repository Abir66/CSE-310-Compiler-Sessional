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
	JMP L5
L3:
	PUSH 4
	PUSH 2
	POP BX
	POP AX
	CMP AX, BX
	JL L4
	JMP L5
L4:
	PUSH 10
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
	JMP L6
L5:
	PUSH 20
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L6:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
L7:
	PUSH 9
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L8:
	MOV AX, [BP-4]
	PUSH AX
	PUSH 5
	POP BX
	POP AX
	CMP AX, BX
	JG L10
	JMP L11
	POP AX
L9:
	MOV AX, [BP-4]
	MOV AX, [BP-4]
	PUSH AX
	DEC AX
	MOV [BP-4], AX
	JMP L8
L10:
	MOV AX, [BP-4]
	CALL print_output
	CALL new_line
	JMP L9
L11:
	PUSH 14
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L12:
L13:
	MOV AX, [BP-4]
	PUSH AX
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JG L14
	JMP L17
L14:
	MOV AX, [BP-4]
	PUSH AX
	PUSH 3
	POP BX
	POP AX
	CMP AX, BX
	JG L15
	JMP L16
L15:
	MOV AX, [BP-4]
	CALL print_output
	CALL new_line
L16:
	MOV AX, [BP-4]
	MOV AX, [BP-4]
	PUSH AX
	DEC AX
	MOV [BP-4], AX
	POP AX
	JMP L13
L17:
	PUSH 30
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L18:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
L19:
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
