/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:55:54 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/02 17:35:28 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char*)(s + n - 1);
	while (ptr >= s)
	{
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		ptr--;
	}
	return (NULL);
}
