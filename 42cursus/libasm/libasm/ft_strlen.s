;nasm -f macho64 ft_strlen.s
;gcc -o ft_strlen ft_strlen.o
section	.text
	global	_ft_strlen

_ft_strlen:
			mov		rax, 0  			; i = 0
			jmp		compare				; loop
compare:
			cmp		BYTE [rdi + rax], 0	; str[i] is null?
			je      done                ; if null done else
			inc		rax					; i++
			jmp     compare				; loop
done:
			ret							; return i