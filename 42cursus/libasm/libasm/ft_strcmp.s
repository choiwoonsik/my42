;nasm -f macho64 ft_strcmp.s
;gcc -o ft_strcmp ft_strcmp.o
section	.text
	global	_ft_strcmp
;int strcmp(const char *s1, const char *s2);

_ft_strcmp:
	mov		rcx, 0
	jmp		compare

next:
	inc			rdi
	inc			rsi
	jmp			compare

compare:
	mov			al, BYTE [rdi]
	mov			bl, BYTE [rsi]
	cmp			al, 0
	jz			return
	cmp			bl, 0
	jz			return
	cmp			al, bl			; if no null
	jne			return
	jmp			next

return:
	movzx		rax, al
	movzx		rbx, bl
	sub			rax, rbx
	ret