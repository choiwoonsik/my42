/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:40:43 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/02 18:47:03 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	j;

	j = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	else if (size <= dest_len)
		return (src_len + size);
	while (*dest != '\0' && size > 1)
	{
		size--;
		dest++;
	}
	while (*(src + j) != '\0' && size > 1)
	{
		*(dest + j) = *(src + j);
		size--;
		j++;
	}
	*(dest + j) = '\0';
	return (src_len + dest_len);
}
