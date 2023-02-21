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
g PROC
	PUSH BP
	MOV BP, SP
	PUSH 5
	PUSH 6
	POP BX
	POP AX
	CMP AX, BX
	JL 
	JMP 
	POP AX
L0:
	SUB SP, 2
	SUB SP, 2
L1:
	PUSH 0
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L2:
	MOV AX, [BP-4]
	PUSH AX
	PUSH 7
	POP BX
	POP AX
	CMP AX, BX
	JL L4
	JMP L5
	POP AX
L3:
	MOV AX, [BP-4]
	MOV AX, [BP-4]
	PUSH AX
	INC AX
	MOV [BP-4], AX
	JMP L2
L4:
	MOV AX, [BP-4]
	CALL print_output
	CALL new_line
	JMP L3
L5:
	SUB SP, 2
L6:
	ADD SP, 6
	POP BP
	RET 4
g ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	PUSH 2
	PUSH 3
	CALL g
	PUSH 0
	POP AX
L7:
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
END main
