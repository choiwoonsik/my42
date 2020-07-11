/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:58:35 by groom             #+#    #+#             */
/*   Updated: 2020/07/10 14:26:38 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		pos_set;
	size_t		start;
	size_t		end;
	size_t		n;
	char		*buf;

	n = 0;
	start = 0;
	pos_set = 0;
	if (!s1)
		return (NULL);
	while (set[pos_set] != '\0')
	{
		if (s1[start] == set[pos_set])
		{
			pos_set = 0;
			start++;
		}
		else
			pos_set++;
	}
	end = 1;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	pos_set = 0;
	while (set[pos_set] != '\0')
	{
		if (s1[ft_strlen(s1) - end] == set[pos_set])
		{
			pos_set = 0;
			end++;
		}
		else
			pos_set++;
	}
	end = ft_strlen(s1) - end + 1;
	if (start > end)
		return (NULL);
	else if (start == end)
		buf = ft_strdup("");
	buf = (char*)malloc(end - start + 1);
	if (!buf)
		return (buf);
	while (start < end)
	{
		buf[n] = s1[start];
		n++;
		start++;
	}
	buf[n] = '\0';
	return (buf);
}
