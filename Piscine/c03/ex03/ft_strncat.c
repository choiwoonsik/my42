/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 13:38:18 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/02 18:47:13 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	u_n;
	int				n;
	int				k;

	n = 0;
	while (*(dest + n) != '\0')
	{
		n++;
	}
	k = n;
	n = 0;
	u_n = 0;
	while (*(src + n) != '\0' && u_n < nb)
	{
		*(dest + k++) = *(src + n++);
		u_n++;
	}
	*(dest + k) = '\0';
	return (dest);
}
