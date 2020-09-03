/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:17:39 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 15:21:08 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list		*buf;
	int			pos;

	pos = 0;
	buf = (t_list*)malloc(sizeof(t_list) * sizeof(content));
	if (!buf)
		return (NULL);
	buf->content = content;
	buf->next = NULL;
	return (buf);
}
