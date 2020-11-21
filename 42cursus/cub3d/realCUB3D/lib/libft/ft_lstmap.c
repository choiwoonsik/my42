/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:50:40 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 15:01:02 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*start;

	start = NULL;
	while (lst)
	{
		new = (t_list*)malloc(sizeof(t_list) * sizeof(f(lst->content)));
		if (!new)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}
