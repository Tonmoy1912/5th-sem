.model small
.stack 100h
.data
prompt db "Enter a letter in uppercase (A-Z): $"
result db "The letter in lowercase is: $"
.code
main proc
    mov ah, 09h        ; Print the prompt
    lea dx, prompt
    int 21h
    
    mov ah, 01h        ; Read a character from the user
    int 21h
    mov bl, al         ; Copy the input character to BL
    
    ; Check if the character is an uppercase letter (A-Z)
    cmp bl, 'A'
    jl not_uppercase
    cmp bl, 'Z'
    jg not_uppercase
    
    ; If it's an uppercase letter, convert it to lowercase
    add bl, 32         ; The difference between 'A' and 'a' in ASCII is 32
    mov al, bl         ; Store the lowercase letter in AL
    
not_uppercase:
    
    mov ah, 09h        ; Print the result message
    lea dx, result
    int 21h
    
    mov dl, al         ; Load the lowercase letter
    mov ah, 02h        ; Print the character in DL
    int 21h
    
    mov ah, 4Ch        ; Exit program
    int 21h
main endp
end main
