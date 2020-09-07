/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:43:44 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 16:20:25 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	char		*buff;

	i = 0;
	buff = malloc(size * count);
	if (!buff)
		return (buff);
	while (i < count * size)
	{
		buff[i] = 0;
		i++;
	}
	return (buff);
}
