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
	SUB SP, 10
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L0:
	PUSH 13
	POP AX
	MOV [BP-14], AX
	PUSH AX
	POP AX
L1:
	MOV AX, [BP-14]
	PUSH AX
	PUSH 12
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP AX
	MOV [BP-16], AX
	PUSH AX
	POP AX
L2:
	MOV AX, [BP-16]
	CALL print_output
	CALL new_line
L3:
	MOV AX, [BP-14]
	PUSH AX
	PUSH 12
	POP BX
	POP AX
	SUB AX, BX
	PUSH AX
	POP AX
	SHL AX, 1
	LEA BX, [BP-2]
	SUB BX, AX
	PUSH BX
	PUSH 10
	POP AX
	POP BX
	MOV [BX], AX
	PUSH AX
	POP AX
L4:
	PUSH 5
	POP AX
	MOV [BP-12], AX
	PUSH AX
	POP AX
L5:
	MOV AX, [BP-14]
	PUSH AX
	PUSH 2
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	PUSH 5
	MOV AX, [BP-12]
	PUSH AX
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
	MOV [BP-16], AX
	PUSH AX
	POP AX
L6:
	MOV AX, [BP-16]
	CALL print_output
	CALL new_line
L7:
	MOV AX, [BP-14]
	PUSH AX
	PUSH 2
	POP BX
	POP AX
	XOR DX, DX
	IMUL BX
	PUSH AX
	PUSH 5
	MOV AX, [BP-12]
	PUSH AX
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
	SHL AX, 1
	LEA BX, [BP-2]
	SUB BX, AX
	PUSH BX
	POP BX
	MOV AX, [BX]
	PUSH AX
	POP AX
	MOV [BP-12], AX
	PUSH AX
	POP AX
L8:
	MOV AX, [BP-12]
	CALL print_output
	CALL new_line
L9:
	ADD SP, 16
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
