/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:36:25 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/07 13:46:14 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
			i++;
		else
			return ((unsigned char*)(s1 + i) - (unsigned char*)(s2 + i));
		i++;
	}
	return (0);
}
