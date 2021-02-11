;nasm -f macho64 ft_strcpy.s
;gcc -o ft_strcpy ft_strcpy.o
section	.text
	global	_ft_strcpy

_ft_strcpy:
	mov     rcx, 0          ; rcx = 0
	mov		rdx, 0			; des = null
	cmp		rsi, 0			; if (src == null)
	jz		return			; 	return
	jmp     copy			; else loop

copy:
	mov		dl, BYTE [rsi + rcx] 	; dl = rsi[rcx]
	mov		BYTE [rdi + rcx], dl 	; rdi[rcx] = dl
	cmp		dl, 0					; if (dl == null)
	jz		return					;	return rdi
	inc		rcx						; rcx++
	jmp		copy					; loop

return:
	mov		rax, rdi				; rax = destination
	ret