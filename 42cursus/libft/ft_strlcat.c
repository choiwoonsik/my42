/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:18:41 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/02 18:37:33 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

size_t		ft_strlcat(char *restrict dst, const char *restrict src,
size_t dstsize)
{
	int		i;

	i = 0;
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (i < dstsize - ft_strlen(dst) - 1 && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src) + ft_strlen(dst));
}
