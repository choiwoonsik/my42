/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:03:26 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 16:22:58 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buf;
	int		i;

	i = 0;
	buf = (char*)malloc(ft_strlen(s1) + 1);
	if (!buf)
		return (buf);
	while (s1[i] != '\0')
	{
		*(buf + i) = *(s1 + i);
		i++;
	}
	*(buf + i) = '\0';
	return (buf);
}
