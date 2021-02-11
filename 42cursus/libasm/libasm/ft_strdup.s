;nasm -f macho64 ft_strdup.s
;gcc -o ft_strdup ft_strdup.o
section	.text
	global	_ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc
;char *strdup(const char *s1);

_ft_strdup:
	cmp     rdi, 0      		; if s1 == null
	jz		control_error
	push	rdi					; s1, 복사할 des, 즉 origin
	push	rsi					; 반환값, 복사 받을 src
	jmp		alloc

alloc:
	call	_ft_strlen			; rdi의 길이 -> rax
	add		rax, 1				; '\0' 공간
	push	rdi					; s1 저장
	mov		rdi, rax			; malloc의 인자로 strlen의 결과 전달
	call	_malloc				; rdi가 첫 번째 인자로 들어감, rdi만큼 할당
	cmp		rax, 0				; if !malloc
	jz		control_error
	mov		rdi, rax			; malloc의 반환값인 할당된 문자열의 주소 rax를 첫번째 인자인 rdi로 전달
	pop		r8					; 넣었던 s1문자열을 꺼낸다
	mov		rsi, r8				; rsi (두번째 인자)로 복사할 문자열을 전달
	call	_ft_strcpy			; strcpy(rdi, rsi)
	pop		rsi					; 초기값 복구
	pop		rdi					; 초기값 복구
	ret

control_error:
	mov		rax, 0
	ret