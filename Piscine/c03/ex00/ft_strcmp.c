/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 09:06:03 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/01 16:41:09 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		my_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		diff;

	diff = my_strcmp(s1, s2);
	if (diff == 0)
		return (0);
	else if (diff < 0)
		return (-1);
	else
		return (1);
}
