/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 10:01:01 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/02 18:47:09 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_all(char *str, char *to_find)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (to_find[i] != '\0')
	{
		if (str[i] == to_find[i])
		{
			i++;
			n = 1;
		}
		else
		{
			n = 0;
			break ;
		}
	}
	return (n);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		n;

	n = 0;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find && check_all(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (0);
}
