.MODEL SMALL
.STACK 300H
.DATA
ARRAY1 DB 50 DUP(?)
MSG5 DB 0AH,0DH,'Enter the elements in the ascending order: $'
MSG4 DB 0AH,0DH,'Enter size of the array: $'
MSG1 DB 0AH,0DH,'Enter number to be searched: $'
MSG2 DB 0AH,0DH,'FOUND AT POSITION $ '
MSG3 DB 0AH,0DH,'NOT FOUND$'
MSG6 DB 0AH,0DH,'NOT FOUND BY BINARY SEARCH$'
MSG7 DB 0AH,0DH,'FOUND BY BINARY SEARCH AT INDEX $'
ENDL DB 0AH,0DH,'$'

SE DB 33H
COUNT DB 00H

.CODE

PRINT MACRO MSG
	push ax
	push dx
	mov AH, 09H
	lea DX, MSG
	int 21H
	;int 3
	pop dx
	pop ax
ENDM

MAIN PROC
	MOV AX,@DATA
	MOV DS,AX

START:

	PRINT MSG4
	call readnum
	mov COUNT, al
	mov cl, COUNT
	mov bx, 00h
    PRINT MSG5
	rdnxt:
		PRINT ENDL
		call readnum
		mov ARRAY1[BX],AL
		inc BX
	loop rdnxt
	
	mov cl, COUNT
	PRINT MSG1
	call readnum
	mov se,al
	mov al,se
	mov ah,00h
	;call writenum
	;PRINT ENDL
	;mov al,se
	;mov ah,00h
	;call writenum
	LEA SI, ARRAY1
	;mov bx, 05h
	;call PRINT_ARRAY
	;MOV CX, 04H
	mov bh, 00h
UP:
	MOV BL,[SI]
	CMP AL, BL
	JZ FO
	INC SI
	inc bh
	loop UP
	PRINT MSG3
	JMP BINARY_SEARCH
 
FO:
	
	PRINT MSG2
	mov al, bh
	call writenum

    ;BINARY SEARCH
    BINARY_SEARCH:
    mov cl,0
    mov ch,COUNT
    dec ch
    LOOP1:
    cmp cl,ch
    jg not_found
    mov ax,0
    mov al,cl
    add al,ch
    mov dl,2
    div dl
    ; mov ah,0
    mov si,ax
    mov al,ARRAY1[si]
    cmp al,se
    je found
    mov ax,si
    jg DECREASE
    mov cl,al
    inc cl
    jmp LOOP1
    DECREASE:
    mov ch,AL
    dec ch
    jmp LOOP1


    not_found:
    print MSG6
    jmp END1

    found:
    print MSG7
    ; mov ax,0
    mov ax,si
    call writenum


END1:
	mov ah, 4ch
	int 21h

MAIN ENDP




readnum proc near
	
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

writenum PROC near
   ; this procedure will display a decimal number
   ; input : AX
   ; output : none

   push bx                        ; push BX onto the STACK
   push cx                        ; push CX onto the STACK
   push dx                        ; push DX onto the STACK

   XOR CX, CX                     ; clear CX
   MOV BX, 10                     ; set BX=10

   @OUTPUT:                       ; loop label
     XOR DX, DX                   ; clear DX
     DIV BX                       ; divide AX by BX
     PUSH DX                      ; push DX onto the STACK
     INC CX                       ; increment CX
     OR AX, AX                    ; take OR of Ax with AX
   JNE @OUTPUT                    ; jump to label @OUTPUT if ZF=0

   MOV AH, 2                      ; set output function

   @DISPLAY:                      ; loop label
     POP DX                       ; pop a value from STACK to DX
     OR DL, 30H                   ; convert decimal to ascii code
     INT 21H                      ; print a character
   LOOP @DISPLAY                  ; jump to label @DISPLAY if CX!=0

   POP DX                         ; pop a value from STACK into DX
   POP CX                         ; pop a value from STACK into CX
   POP BX                         ; pop a value from STACK into BX

   RET                            ; return control to the calling procedure
writenum ENDP
	
END MAIN