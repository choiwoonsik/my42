/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:17:09 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 15:28:48 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(src + i) == (unsigned char)c)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			return (dst + i + 1);
		}
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		i++;
	}
	return (NULL);
}
