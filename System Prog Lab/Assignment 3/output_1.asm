.model small
.stack 300h
.data
msg1 db 0AH,0DH,'ENTER 1ST NUMBER: $'
msg2 db 0AH,0DH,'ENTER 2ND NUMBER: $'
msg3 db 0AH,0DH,'THE RESULT AFTER ADDITION IS: $'
msg4 db 0AH,0DH,'THE RESULT AFTER SUBTRACTION IS: $'
space db ' $'
endl db 0AH,0DH,'$'

val1 dw ?
val2 dw ?

.code
print macro msg var1
	push ax
	push dx
	mov ah, 09h
	lea dx, msg
	int 21h
	pop dx
	pop ax
endm

main proc
	mov ax,@data
	mov ds,ax
	
	start:
	
	push ax
	push dx
	mov ah, 09h
	lea dx, msg1
	int 21h
	pop dx
	pop ax
	

	push ax
	push dx
	mov ah, 09h
	lea dx, msg2
	int 21h
	pop dx
	pop ax
	
	exit:
    mov ah, 4ch
    int 21h

main endp
