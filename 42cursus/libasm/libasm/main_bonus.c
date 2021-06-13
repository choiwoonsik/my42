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
	t_list *lst;
	t_list *tmp;
	lst = ft_create_elem("8");
	lst->next = ft_create_elem("2");
	lst->next->next = ft_create_elem("3");
	lst->next->next->next = ft_create_elem("4");
	lst->next->next->next->next = ft_create_elem("7");
	lst->next->next->next->next->next = ft_create_elem("9");
	ft_list_push_front_bonus(&lst, "000");
	tmp = lst;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("LST SIZE:%d\n", ft_list_size_bonus(lst));
}