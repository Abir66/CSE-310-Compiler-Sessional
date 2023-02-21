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
	SUB SP, 2
L0:
; ------------------ Line 6 ------------------
	PUSH 5
	POP AX
	MOV [BP-2], AX
	PUSH AX
	POP AX
L1:
	MOV AX, [BP-2]
	PUSH AX
	PUSH 2
	POP AX
	NEG AX
	PUSH AX
	POP BX
	POP AX
	CMP AX, BX
	JG L3
	JMP L6
	POP AX
L2:
	MOV AX, [BP-2]
	PUSH AX
	DEC AX
	MOV [BP-2], AX
	POP AX
	JMP L1
L3:
; ------------------ Line 8 ------------------
	MOV AX, [BP-2]
	PUSH AX
	PUSH 2
	POP BX
	POP AX
	XOR DX, DX
	IDIV BX
	PUSH DX
	POP AX
	MOV [BP-4], AX
	PUSH AX
	POP AX
L4:
; ------------------ Line 10 ------------------
	MOV AX, [BP-4]
	PUSH AX
	POP AX
	CMP AX, 0
	JNE L5
	JMP L2
L5:
; ------------------ Line 11 ------------------
	MOV AX, [BP-2]
	CALL print_output
	CALL new_line
	JMP L2
L6:
	ADD SP, 4
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
