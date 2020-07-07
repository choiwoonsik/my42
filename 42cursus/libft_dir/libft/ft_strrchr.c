/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:54:11 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/07 13:55:08 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rt_s;
	char	*pos;

	pos = NULL;
	i = 0;
	rt_s = (char *)s;
	while (*(rt_s + i) != '\0')
	{
		if (*(rt_s + i) == (char)c)
		{
			pos = rt_s + i;
		}
		i++;
	}
	if (*(rt_s + i) == '\0' && (*(rt_s + i) == (char)c))
		return (pos);
	return (NULL);
}
