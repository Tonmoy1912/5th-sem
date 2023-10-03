.model small
.stack 300h
.data
msg1 db 0AH,0DH,'Enter 3 numbers: $'
msg2 db 0AH,0DH,'GCD: $'
msg3 db 0AH,0DH,'LCM: $'
space db ' $'
endl db 0AH,0DH,'$'

val1 dw ?
val2 dw ?
val3 dw ?
num1 dw ?;gcd(a,b)
num2 dw ?;gcd(a,b,c)
num3 dw ?;gcd(a,c)
num4 dw ?;gcd(b,c)

.code
print macro msg
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
	
	print msg1
	
	call readnum
	mov val1, ax

	call readnum
	mov val2, ax

	call readnum
	mov val3, ax
	
	
	
    ;computing gcd(a,b)
    mov dx, 0000h
	mov bx, val1
	mov cx, val2
	loopgcd:
		mov ax, bx
		mov dx, 0000h
		div cx
		cmp dx,0000h
		jz ans
		mov bx,cx
		mov cx,dx
		;mov ax,bx
		;call writenum
		;mov ax,cx
		;call writenum
		cmp cx, 0001h
	jnz loopgcd
	ans:
	mov num1, cx

    ;computing gcd(a,b,c)
	mov dx, 0000h
	mov bx, val3
	
	loopgcd1:
		mov ax, bx
		mov dx, 0000h
		div cx
		cmp dx, 0000h
		jz ans1
		mov bx, cx
		mov cx, dx
		cmp cx, 0001h
	jnz loopgcd1

	ans1:
	
	print msg2
	mov ax, cx
    mov num2,ax
	call writenum


    ;computing gcd(a,c)
    mov dx, 0000h
	mov bx, val1
	mov cx, val3
	loopgcd2:
		mov ax, bx
		mov dx, 0000h
		div cx
		cmp dx,0000h
		jz ans2
		mov bx,cx
		mov cx,dx
		;mov ax,bx
		;call writenum
		;mov ax,cx
		;call writenum
		cmp cx, 0001h
	jnz loopgcd2
	ans2:
	mov num3, cx



    ;computing gcd(b,c)
    mov dx, 0000h
	mov bx, val2
	mov cx, val3
	loopgcd3:
		mov ax, bx
		mov dx, 0000h
		div cx
		cmp dx,0000h
		jz ans3
		mov bx,cx
		mov cx,dx
		;mov ax,bx
		;call writenum
		;mov ax,cx
		;call writenum
		cmp cx, 0001h
	jnz loopgcd3
	ans3:
	mov num4, cx


	
	mov ax, val1
	mov bx, val2
	mul bx
	mov bx, num1
	div bx
	;ax = lcm(a,b)
	mov bx, val3
	mul bx
	;ax=lcm(a,b)*c
    mov bx,num3
    div bx
    ;ax=lcm(a,b)*c/gcd(a,c)
    mov bx,num2
    mul bx
    ;ax=lcm(a,b)*c*gcd(a,b,c)/gcd(a,c)
    mov bx,num4
    div bx
    ;ax=lcm(a,b)*c*gcd(a,b,c)/gcd(a,c)/gcd(b,c)
	
	print msg3
	call writenum
	
	exit:
    mov ah, 4ch
    int 21h

main endp

readnum proc near
	; this procedure will take a number as input from user and store in AX
	; input : none
	
	; output : AX

	
	push bx
	push cx
	mov cx,0ah
	mov bx,00h
	loopnum: 
		mov ah,01h
		int 21h
		cmp al,'0'
		jb skip
		cmp al,'9'
		ja skip
		sub al,'0'
		push ax
		mov ax,bx
		mul cx
		mov bx,ax
		pop ax
		mov ah,00h
		add bx,ax
	jmp loopnum
	
	skip:
	mov ax,bx
	pop cx
	pop bx
	ret
readnum endp

writenum proc near
	; this procedure will display a decimal number
	; input : AX
	; output : none

	push ax
	push bx                        
	push cx                        
	push dx                        

	xor cx, cx
	mov bx, 0ah                     

	@output:                       
		xor dx, dx                   
		div bx                       ; divide AX by BX
		push dx                      ; push remainder onto the STACK
		inc cx                       
		or ax, ax                    
	jne @output                    

	mov ah, 02h                      ; set output function

	@display:                      
		pop dx                       ; pop a value(remainder) from STACK to DX
		or dl, 30h                   ; convert decimal to ascii code
		int 21h                      
	loop @display                  

	pop dx                         
	pop cx                         
	pop bx 
	pop ax

	ret                            
writenum endp

end main