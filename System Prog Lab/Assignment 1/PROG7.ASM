.model small
.stack 100h
.data

    msg1 db "Second number is less than the first number",10,13,"$"
    msg2 db "Second number is not less than the first number",10,13,"$"

.code

    mov ax,@data
    mov ds,ax
    
    mov bx,0012h
    mov cx,0012h

    cmp cx,bx

    jl step1

    mov ah,09h
    lea dx,msg2
    int 21h

    jmp step2

step1:
    mov ah,09h
    lea dx,msg1
    int 21h

step2:
    mov ah,4Ch        
    int 21h

end