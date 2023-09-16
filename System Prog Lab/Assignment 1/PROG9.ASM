.model small
.stack 100h
.data

    termi_msg db 13,10,"The program is about to terminate.... $"
    msg db 13,10,"Press 'q' to terminate : $"

.code

    mov ax,@data
    mov ds,ax
    
loop1:

    mov ah,09h
    lea dx,msg
    int 21h

    mov ah,01h
    int 21h

    cmp al,'q'
    jne loop1

    mov ah,09h
    lea dx,termi_msg
    int 21h

    mov ah,4Ch        
    int 21h

end