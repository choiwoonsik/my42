/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:07:49 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/18 20:58:44 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "srcs/ft_printf.h"
#include "srcs/gnl/get_next_line.h"
#include "srcs/libft/libft.h"
#include "astree.h"


int main(int argc, char *argv[])
{
	//t_list *list = ft_lstnew("start");
	//ft_printf("%s\n", list->content);
	t_tock *tlist;
	tlist = malloc(sizeof(t_tock));

	t_tock *head;
	head = malloc(sizeof(t_tock));
	head = tlist;

	t_tock *head2;
	head2 = malloc(sizeof(t_tock));
	head2 = tlist;

	char	*s = "data";
	
	int i;
	for (i = 0; i < ft_strlen(argv[1]); i++)
	{
		tlist->type = (char)malloc(sizeof(char) + 1);
		tlist->type = argv[1][i];
		tlist->data = malloc(sizeof(char) * (ft_strlen(s + 1)));
		tlist->data = s;
		
		ft_printf("%c - ", tlist->type);
		ft_printf("%s = ", tlist->data);
		tlist->next = malloc(sizeof(t_tock));
		tlist = tlist->next;
	}

	ft_printf("%d\n", i);

	int len = i;
	i = 0;
	while (i < len)
	{
		ft_printf("%c > ", head->type);
		ft_printf("%s = ", head->data);
		head = head->next;
		i++;
	}
	ft_printf("\n");
	parse(head2, NULL, len);
}