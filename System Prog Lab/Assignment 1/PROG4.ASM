.model small
.stack 100h
.data
    arr     db 25 dup(00h)
    n       db 00h
    index   db 00h
    max     db 00h
    min     db 00h
    max2     db 00h
    min2     db 00h
    prompt1 db 10,13,"Enter the number of elements: $"
    prompt2 db 10,13,"Enter the element: $"
    prompt3 db 10,13,"The max element: $"
    prompt4 db 10,13,"The min element: $"
.code
main:

         mov ax,@data
    ;for moving data to data segment
         mov ds,ax

        ;  mov min,feh
        ;  mov max,00h

        lea dx,prompt1
        mov ah,09h
        int 21h

        call in_put
        mov n,bl

        mov index,00h
        mov si,0000h
    input_loop:
        mov cl,index
        cmp cl,n
        jge skip1

        lea dx,prompt2
        mov ah,09h
        int 21h

        call in_put
        ; mov dl,index
        mov arr[si],bl
        inc index
        inc si
        jmp input_loop


    skip1:
        ;finding the max element
        mov index,00h
        mov si,0000h
    max_loop:
        mov cl,index
        cmp cl,n
        jge skip2

        mov cl,max
        ; mov dl,index
        cmp cl,arr[si]
        jge com_max2
        ; mov dl,index
        mov max2,cl
        mov cl,arr[si]
        mov max,cl
        jmp not_take_max

        com_max2:
        mov cl,max2
        cmp cl,arr[si]
        jge not_take_max
        mov cl,arr[si]
        mov max2,cl

        not_take_max:
        inc index
        inc si
        jmp max_loop

    skip2:
        lea dx,prompt3
        mov ah,09h
        int 21h

        mov bl,max2
        call out_put


        mov index,00h
        mov si,0000h

        ; mov cl,arr[si]
        mov cl,max
        mov min,cl
        mov min2,cl
    min_loop:
        mov cl,index
        cmp cl,n
        jge skip3

        mov cl,min
        ; mov dl,index
        cmp cl,arr[si]
        jle com_min2
        ; mov dl,index
        mov min2,cl
        mov cl,arr[si]
        mov min,cl
        jmp not_take_min

        com_min2:
        mov cl,min2
        cmp cl,arr[si]
        jle not_take_min
        mov cl,arr[si]
        mov min2,cl

        not_take_min:
        inc index
        inc si
        jmp min_loop

    skip3:
        lea dx,prompt4
        mov ah,09h
        int 21h

        mov bl,min2
        call out_put


        mov ah,4ch
        int 21h



in_put proc
;it take the input in bl redister in hexadecimal format
;it also use al,ah,bl register

        xor bl,bl 

        mov cl,04h
          mov ah,1                                    
;for taking input
          int 21h
      
      
      input1:
          cmp al,0dh                                  
;compare whether the pressed key is 'enter' or not
          je line1                                    
;if it is equal to 'enter' then stop taking first value
         
          cmp al,39h                                  
;compare the input whether it is letter or digit.39h is the ascii value of 9
          jg letter1
          
          sub al,'0'                                  
;if it is digit then convert it's ascii value to real value by masking
          jmp shift1
          
      letter1:                                        
;if it is letter then subtract 37h from it to find it's real value
          sub al,37h
       
      shift1:
          shl bl,cl
          or  bl,al                                   
;making 'or' will add the current value with previous value
          
          int 21h
          jmp input1
      line1:
          ret
in_put endp

out_put proc
;it out put the number store in bl register on console in hexadecimal format
;it uses ah,bl,ch,dl registers

        mov cl,04h
        mov ch,bl
          shr ch,cl
          and ch,0fh
        ;   cmp ch,10
          add ch,'0'
          cmp ch,':'
          jl tag2
          add ch,7
      tag2:mov dl,ch
          mov ah,2
          int 21h

          mov ch,bl
          and ch,0fh
        ;   cmp ch,10
          add ch,'0'
          cmp ch,':'
          jl tag3
          add ch,7
      tag3:mov dl,ch
          mov ah,2
          int 21h
        ret

out_put endp
      
end main