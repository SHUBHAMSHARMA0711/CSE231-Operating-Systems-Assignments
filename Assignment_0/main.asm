segment .data
	msg0: db " " , 10 , 0
	msg1: db "Enter the Number: " , 0
	msg2: db "Enter the String: " , 0
	msg3: db "Entered Number is: %d" , 10 , 0
	msg4: db "Entered String is: %s" , 10 , 0
	input_format1: db "%d" , 0
	input_format2: db "%s" , 0

segment .bss
	numIO: resb 1000
	strIO: resb 1000

segment .text
	global main
	extern scanf
	extern printf

main:
	push rbp
        mov rbp , rsp

        mov rax , 0
        lea rdi , [msg1]
        call printf		       ; Printing Message on Console

        mov rax , 0
        lea rdi , [input_format1]
        lea rsi , [numIO]
        call scanf                     ; Taking Number Input from User using Scanf

	mov rax , 0
        lea rdi , [msg2]
        call printf                    ; Printing Message on Console

	mov rax , 0
        lea rdi , [input_format2]
        lea rsi , [strIO]
        call scanf		       ; Taking String Input from User using Scanf

	mov rax , 0
        lea rdi , [msg0]
        call printf		       ; Just Printing Blank Line using Printf

        mov rax , 0
	lea rdi , [msg3]
        mov rsi , [numIO]
        call printf		       ; Printing Number Entered by User using Printf

        mov rax , 0
        lea rdi , [msg4]
	mov rsi , strIO
        call printf		       ; Printing String Entered by User using Printf

        leave
        ret
