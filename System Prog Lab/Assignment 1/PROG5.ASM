.model small
.stack 100h
.data

    termi_msg db 13,10,"The program is about to terminate.... $"
    msg db "Press a key to terminate the program :$"

.code

    mov ax,@data
    mov ds,ax
    
    mov ah,09h
    lea dx,msg
    int 21h

    mov ah,01h
    int 21h

    mov ah,09h
    lea dx,termi_msg
    int 21h

    mov ah,4Ch        
    int 21h

end