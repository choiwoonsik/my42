;nasm -f macho64 ft_list_size_bonus.s
;gcc -o ft_list_size_bonus ft_list_size_bonus.o
; typedef struct		s_list
; {
; 	void			*data;
; 	struct s_lsit	*next
; }					t_list;

section	.text
	global	_ft_list_size_bonus

_ft_list_size_bonus:
	mov		rcx, 0
	jmp		isnull

next:
	inc		rcx

isnull:
	cmp		rdi, 0
	jz		end

count:
	mov		rdi, [rdi + 8]
	jmp		next

end:
	mov		rax, rcx
	ret

