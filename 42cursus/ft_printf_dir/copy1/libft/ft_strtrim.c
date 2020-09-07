/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:58:35 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 17:53:00 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_start(char const *s1, char const *set)
{
	size_t		pos_set;
	size_t		start;

	start = 0;
	pos_set = 0;
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
	return (start);
}

int		find_end(char const *s1, char const *set)
{
	size_t		pos_set;
	size_t		end;

	end = 1;
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
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		n;
	char		*buf;

	if (!s1)
		return (0);
	if ((start = find_start(s1, set)) == ft_strlen(s1))
		return (ft_strdup(""));
	end = find_end(s1, set);
	if (start > end)
		return (NULL);
	else if (start == end)
		return (ft_strdup(""));
	if (!(buf = (char*)malloc(end - start + 1)))
		return (buf);
	n = -1;
	while (start < end)
	{
		buf[++n] = s1[start];
		start++;
	}
	buf[n + 1] = '\0';
	return (buf);
}
