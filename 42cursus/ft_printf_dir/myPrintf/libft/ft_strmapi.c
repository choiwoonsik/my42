/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:56:21 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 16:22:41 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		pos;
	int		s_len;
	char	*buf;
	char	word;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	buf = (char*)malloc(s_len + 1);
	if (!buf)
		return (NULL);
	pos = 0;
	while (s[pos] != '\0')
	{
		word = f(pos, s[pos]);
		if (!word)
			return (NULL);
		buf[pos] = word;
		pos++;
	}
	buf[s_len] = '\0';
	return (buf);
}
