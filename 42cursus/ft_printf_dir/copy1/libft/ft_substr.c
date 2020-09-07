/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:13:16 by groom             #+#    #+#             */
/*   Updated: 2020/07/09 23:42:42 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		pos;
	size_t		word_len;
	char		*word;

	pos = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	word_len = (ft_strlen(s) - start < len) ? ft_strlen(s) - start : len;
	if (start + word_len > ft_strlen(s) || word_len > ft_strlen(s))
		return (NULL);
	word = (char*)malloc(word_len + 1);
	if (!word)
		return (word);
	while (pos < word_len && s[start + pos])
	{
		word[pos] = s[start + pos];
		pos++;
	}
	word[pos] = '\0';
	return (word);
}
