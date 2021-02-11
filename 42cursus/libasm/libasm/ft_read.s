;nasm -f macho64 ft_read.s
;gcc -o ft_read ft_read.o
section	.text
	global	_ft_read
	extern ___error

_ft_read:
	mov			rax, 0x2000003
	syscall							; read함수 호출
	jc			control_error		; check carry flag
	ret

control_error:
	push		rax
	call		___error
	pop			qword [rax]
	mov			rax, -1
	ret