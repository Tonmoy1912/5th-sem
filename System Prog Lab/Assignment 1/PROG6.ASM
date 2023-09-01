.model small
.stack 100h
.data
    msg1 db "Press a key: ",'$'
    msg2 db 13,10,"Entered key is $"

.code 
    mov ax,@data
    mov ds,ax

    mov ah,09h
    lea dx,msg1
    int 21h

    mov ah,01h
    int 21h

    mov ah,09h
    lea dx,msg2
    int 21h

    mov ah,02h
    mov dl,al
    int 21h

    mov ah, 4Ch
    int 21h
end