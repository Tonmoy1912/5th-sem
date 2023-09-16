.model small
.stack 100h
.data
    prompt db "Enter a letter in uppercase (A-Z): $"
    result db 13,10,"The letter in lowercase is: $"


.code
main proc

    mov ax,@data
    mov ds,ax

    mov ah,09h        
    lea dx,prompt
    int 21h
    
    mov ah,01h        
    int 21h
    mov bl,al         
    
    cmp bl,'A'
    jl not_uppercase
    cmp bl,'Z'
    jg not_uppercase
    
    
    add bl,32         
    mov al,bl         
    
not_uppercase:
    
    mov ah,09h        
    lea dx,result
    int 21h
    
    mov dl,al         
    mov ah,02h        
    int 21h
    
    mov ah,4Ch        
    int 21h
main endp
end main
