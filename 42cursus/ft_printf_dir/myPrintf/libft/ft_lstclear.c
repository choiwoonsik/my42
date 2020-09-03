/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 18:49:45 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 15:23:46 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!lst)
		return ;
	while ((*lst))
	{
		buf = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = buf;
	}
}
