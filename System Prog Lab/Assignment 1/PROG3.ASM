
.model small
.stack 100h
.data

    ; x db 12
    ; y db 11

.code

    mov ax,@data
    mov ds,ax

    mov ax,1234h
    mov bx,1111h

    mov cx,0000;it contains the carray

    add ax,bx

    jnc skip
    inc cx

skip:

    ; mov ah,4Ch
    ; int 21h
    int 3


end
