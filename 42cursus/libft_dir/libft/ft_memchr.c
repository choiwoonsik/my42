/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:55:54 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/07 14:58:11 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*s2;

	count = 0;
	s2 = (unsigned char*)s;
	while (n-- > 0)
	{
		if (s2[count] == (unsigned char)c)
			return (s2 + count);
		else
			count++;
	}
	return (NULL);
}
