/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:18:41 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/07 22:30:48 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst, const char *restrict src,
size_t dstsize)
{
	size_t		i;
	size_t		src_len;
	size_t		dst_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize == 0)
		return (src_len);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[i] != '\0' && dstsize - dst_len > 1 && dstsize)
	{
		dst[dst_len + i] = src[i];
		dstsize--;
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
