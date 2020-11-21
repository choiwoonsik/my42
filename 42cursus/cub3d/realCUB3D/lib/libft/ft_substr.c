/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:13:16 by groom             #+#    #+#             */
/*   Updated: 2020/11/17 16:14:50 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		pos;
	char		*word;

	pos = 0;
	if (!s)
		return (NULL);
	if (!(word = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + pos] && pos < len)
		{
			word[pos] = s[start + pos];
			pos++;
		}
	}
	word[pos] = '\0';
	return (word);
}
