/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:47:27 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/30 18:14:09 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		str_len;
	size_t		pr_pos;
	size_t		sf_pos;
	char		*sum_str;

	if (!s1 || !s2)
		return (NULL);
	pr_pos = -1;
	sf_pos = -1;
	str_len = ft_strlen(s1) + ft_strlen(s2);
	sum_str = (char*)malloc(str_len + 1);
	if (!sum_str)
		return (sum_str);
	while (++pr_pos < ft_strlen(s1))
		sum_str[pr_pos] = s1[pr_pos];
	while (++sf_pos < ft_strlen(s2))
		sum_str[pr_pos + sf_pos] = s2[sf_pos];
	sum_str[str_len] = '\0';
	return (sum_str);
}

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