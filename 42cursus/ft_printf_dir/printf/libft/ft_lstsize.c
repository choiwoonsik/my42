/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:04:47 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 15:29:25 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	if (!lst)
		return (0);
	while (lst->next)
	{
		count++;
		lst = lst->next;
	}
	count++;
	return (count);
}
