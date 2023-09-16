.model small
.stack 100h
.data

    ; termi_msg db 13,10,"The program is about to terminate.... $"
    msg db 13,10,"$"

.code

    mov ax,@data
    mov ds,ax
    
    mov cl,26
    mov al,'A'

loop1:

    mov dl,al
    mov ah,02h
    int 21h

    mov ah,09h
    lea dx,msg
    int 21h

    inc al
    dec cl

    jnz loop1

    mov ah,4Ch        
    int 21h

end