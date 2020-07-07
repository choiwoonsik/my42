/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:32:39 by groom             #+#    #+#             */
/*   Updated: 2020/07/07 13:23:50 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnlen(char *str, size_t maxlen)
{
	int		len;
	
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len > (int)maxlen ? len : (int)maxlen);
}

char    *ft_strnstr(const char* haystack, const char *needle, size_t len)
{
	size_t     	i;
	size_t     	j;
	char		*_haystack;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (0 == ft_strnlen((char *)needle, len))
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			_haystack = (char *)(haystack + i);
			while (needle[j] != '\0' && i < len)
			{
				if (haystack[i] !=  needle[j])
					return (NULL);
				i++;
				j++;
			}
			return (_haystack);
		}
		i++;
	}
	return (NULL);
}
