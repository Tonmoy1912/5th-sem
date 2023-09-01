.model small
.stack 100h
.data
  pr1 db 'Enter the Uppercase:$'
  pr2 db 'Lowercase is:$' 
.code
main proc
  mov ax, @data
  mov ds, ax

  lea dx, pr1
  mov ah, 9
  int 21h

  mov ah, 1
  int 21h

  mov bl, al

  mov ah, 2
  mov dl, 0dh
  int 21h

  mov dl,0ah
  int 21h

  lea dx, pr2
  mov ah, 9
  int 21h

  add bl, 20h

  mov ah, 2
  mov dl, bl
  int 21h

  mov ah, 4Ch
  int 21h
 main endp
 end main
