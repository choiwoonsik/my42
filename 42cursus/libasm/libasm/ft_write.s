;nasm -f macho64 ft_write.s
;gcc -o ft_write ft_write.o
section	.text
	global	_ft_write
	extern ___error

_ft_write:
	mov		rax, 0x2000004		; write 함수 호출을 위해 rax 변경
	syscall
	jc		control_error		; if carry flag
	ret

control_error:
	push	rax					; 에러값 저장
	call	___error			; error 함수 호출
	pop		qword [rax]			; 에러값을 qword로 바꿔서 [rax]에 저장
	mov		rax, -1
	ret
