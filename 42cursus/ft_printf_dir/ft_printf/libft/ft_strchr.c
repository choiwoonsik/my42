/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:37:55 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/07 13:49:07 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*rt_s;

	i = 0;
	rt_s = (char *)s;
	while (*(rt_s + i) != '\0')
	{
		if (*(rt_s + i) == (char)c)
		{
			return (rt_s + i);
		}
		i++;
	}
	if (*(rt_s + i) == '\0' && (*(rt_s + i) == (char)c))
		return (rt_s + i);
	return (NULL);
}
