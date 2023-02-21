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
f PROC
	PUSH BP
	MOV BP, SP
	MOV AX, [BP+4]
	CALL print_output
	CALL new_line
L0:
	MOV AX, [BP+4]
	PUSH AX
	PUSH 1
	POP BX
	POP AX
	CMP AX, BX
	JE L1
	JMP L2
L1:
	PUSH 1
	POP AX
	JMP L3
L2:
	MOV AX, [BP+4]
	PUSH AX
	MOV AX, [BP+4]
	PUSH AX
	PUSH 1
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	CALL f
	PUSH AX
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	JMP L3
L3:
	ADD SP, 0
	POP BP
	RET 2
f ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 20
	SUB SP, 2
L4:
	PUSH 5
	CALL f
	PUSH AX
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
L5:
	MOV AX, [BP-2]
	CALL print_output
	CALL new_line
L6:
	PUSH 5
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
L7:
	PUSH 6
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L8:
	MOV AX, [BP-2]
	PUSH AX
	MOV AX, [BP-4]
	PUSH AX
	POP BX
	POP AX
	CMP AX, BX
	JL L9
	JMP L11
L9:
	MOV AX, [BP-2]
	PUSH AX
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JG L10
	JMP L11
	PUSH AX
L10:
	PUSH 1
	JMP L12
L11:
	PUSH 0
L12:
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L13:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
L14:
	MOV AX, [BP-2]
	PUSH AX
	MOV AX, [BP-4]
	PUSH AX
	POP BX
	POP AX
	CMP AX, BX
	JG L16
	JMP L15
L15:
	PUSH 5
	PUSH 5
	POP BX
	POP AX
	CMP AX, BX
	JNE L16
	JMP L17
	PUSH AX
L16:
	PUSH 1
	JMP L18
L17:
	PUSH 0
L18:
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L19:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
L20:
	PUSH 5
	PUSH 6
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	PUSH 2
	PUSH 3
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
L21:
	MOV AX, [BP-2]
	CALL print_output
	CALL new_line
L22:
	MOV AX, [BP-2]
	PUSH AX
	PUSH 2
	POP BX
	POP AX
	XOR DX, DX
	IDIV BX
	PUSH AX
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L23:
	MOV AX, [BP-4]
	CALL print_output
	CALL new_line
L24:
	PUSH 1
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L25:
	MOV AX, [BP-26]
	PUSH AX
	PUSH 2
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	SHL AX, 1
	LEA BX, [BP-6]
	SUB BX, AX
	PUSH BX
	MOV AX, [BP-2]
	PUSH AX
	PUSH 3
	POP BX
	POP AX
	XOR DX, DX
	IDIV BX
	PUSH AX
	PUSH 5
	PUSH 2
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	PUSH 1
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	POP BX
	MOV [BX], AX
	PUSH AX
	POP AX
L26:
	PUSH 1
	MOV AX, [BP-26]
	PUSH AX
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	PUSH 1
	POP BX
	POP AX
	ADD AX, BX
	PUSH AX
	POP AX
	SHL AX, 1
	LEA BX, [BP-6]
	SUB BX, AX
	PUSH BX
	POP BX
	MOV AX, [BX]
	PUSH AX
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L27:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
L28:
	MOV AX, [BP-26]
	PUSH AX
	PUSH 3
	POP BX
	POP AX
	XOR DX, DX
	IDIV BX
	PUSH DX
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L29:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
L30:
	MOV AX, [BP-26]
	PUSH AX
	PUSH 3
	POP BX
	POP AX
	XOR DX, DX
	IDIV BX
	PUSH DX
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L31:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
L32:
	PUSH 100
	POP AX
	MOV [BP-26], AX
	PUSH AX
	POP AX
L33:
	MOV AX, [BP-26]
	PUSH AX
	PUSH 0
	POP BX
	POP AX
	CMP AX, BX
	JG L35
	JMP L36
	POP AX
L34:
	MOV AX, [BP-26]
	MOV AX, [BP-26]
	PUSH AX
	DEC AX
	MOV [BP-26], AX
	JMP L33
L35:
	MOV AX, [BP-26]
	CALL print_output
	CALL new_line
	JMP L34
L36:
	PUSH 0
	POP AX
	JMP L37
L37:
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
END main
