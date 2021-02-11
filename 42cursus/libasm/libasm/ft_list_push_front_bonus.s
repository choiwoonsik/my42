;void	ft_list_push_front(t_list **list, void *data)
;{
;	t_list *new;
;
;	new = malloc(16);
;	if (new == 0)
;		return ;
;	new->content = data;
;	new->next = *list;
;	*list = node;
;}
section	.text
	global	_ft_list_push_front_bonus
	extern _malloc

_ft_list_push_front_bonus:
	cmp		rdi, 0
	je		return

malloc:
	push	rsp
	push	rdi			; list
	push	rsi			; data
	mov		rdi, 16
	mov		rax, 0
	call	_malloc		; 16만큼 할당
	pop		rsi
	pop		rdi
	cmp		rax, 0		; if !malloc
	jz		return
	jmp		copy

copy:
	mov		[rax], rsi		; 할당된 주소 rax로 data 전달
	mov		rcx, [rdi]		; rcx에 rdi의 주소를 저장
	mov		[rax + 8], rcx	; 새로 할당한 rax 다음 주소에 기존 rdi 주소를 이어 붙인다 
	mov		[rdi], rax		; 그담 rax다시 기존의 rdi로 전달

return:
	pop		rsp
	ret
