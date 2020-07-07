/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:47:13 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/01 10:14:57 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	char	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		if ((*(str + n) >= 'A') && (*(str + n) <= 'Z'))
			*(str + n) += 32;
		n++;
	}
	*(str + n) = '\0';
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		n;

	n = 0;
	str = ft_strlowcase(str);
	while (*(str + n) != '\0')
	{
		if (*(str + n) >= ('a') && *(str + n) <= 'z')
		{
			if ((*(str + n - 1) < '0') || ((*(str + n - 1) > '9')
				&& (*(str + n - 1) < 'A')) || ((*(str + n - 1) > 'Z')
				&& (*(str + n - 1) < 'a')) || (*(str + n - 1) > 'z'))
			{
				*(str + n) -= 32;
			}
		}
		n++;
	}
	return (str);
}
