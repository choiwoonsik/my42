#include "libasm.h"

t_list *ft_create_elem(void *data)
{
	t_list *elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

int main(void)
{
	// ASSEMBLY SUBJECT TEST

	printf("ASM FT_STRLEN TEST\n\n");

	char *str = "this str length is 22\n";
	printf("assembly ft_strlen > %d\t vs. strlen() > %d\n", ft_strlen(str), strlen(str));

	// 리스트의 앞에 구조체 변수 추가
	printf("ASM FT_LIST_PUSH_FRONT TEST\n");

	t_list *lst;
	t_list *tmp;
	lst = ft_create_elem("8");
	lst->next = ft_create_elem("2");
	lst->next->next = ft_create_elem("3");
	lst->next->next->next = ft_create_elem("4");
	lst->next->next->next->next = ft_create_elem("7");
	lst->next->next->next->next->next = ft_create_elem("9");
	ft_list_push_front_bonus(&lst, "000"); // <-- "000"을 맨앞에 넣는다
	tmp = lst;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}

	// 리스트의 길이를 반환
	printf("ASM FT_LIST_SIZE TEST\n");
	printf("LST SIZE:%d\n", ft_list_size_bonus(lst));
}