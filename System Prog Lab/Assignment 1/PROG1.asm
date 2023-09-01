.model small
.stack 100h
.data
  message1 db "Name: Tonmoy Biswas",'$'
  message2 db "Title: PROG1",'$'

.code
  mov ax, @data
  mov ds, ax

  lea dx, message1
  mov ah, 09h
  int 21h

  lea dx, message2
  mov ah, 09h
  int 21h

  mov ah, 4Ch
  int 21h

end 
