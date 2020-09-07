/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:54:11 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/07 19:10:32 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	pos = NULL;
	while (*s)
	{
		if (*s == (char)c)
			pos = (char *)s;
		s++;
	}
	if (*s == (char)c)
		pos = (char *)s;
	return (pos);
}
