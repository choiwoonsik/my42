/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:55:54 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/07 13:45:50 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)(s + n - 1);
	while (ptr >= (char *)s)
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr--;
	}
	return (NULL);
}
