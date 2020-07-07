/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:29:44 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/15 21:18:24 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

int		count_len(int size, char **strs, char *sep)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += (ft_strlen(sep) * (size - 1));
	return (len);
}

char	*mk_str(char **strs, int len, int size, char *sep)
{
	char	*str_all;
	int		word;
	int		pos;
	int		j;
	int		k;

	pos = 0;
	str_all = (char*)malloc(sizeof(char) * (len + 1));
	if (!str_all)
		return (0);
	str_all[len] = '\0';
	word = 0;
	while (word < size)
	{
		j = 0;
		while (strs[word][j] != '\0')
			str_all[pos++] = strs[word][j++];
		k = 0;
		while (k < ft_strlen(sep) && (word < size - 1))
			str_all[pos++] = sep[k++];
		word++;
	}
	return (str_all);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;

	if (size == 0)
		return ((char*)malloc(sizeof(char)));
	len = count_len(size, strs, sep);
	return (mk_str(strs, len, size, sep));
}
