/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:54:48 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/15 12:00:20 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*g_str;
char	*g_sep;

int		is_sep(char c)
{
	int		i;

	i = 0;
	while (g_sep[i] != '\0')
	{
		if (c == g_sep[i])
			return (1);
		i++;
	}
	return (0);
}

int		count_of_word(void)
{
	int		str_pos;
	int		word_count;

	str_pos = 0;
	word_count = 0;
	while (g_str[str_pos] != '\0')
	{
		if ((!is_sep(g_str[str_pos]) && is_sep(g_str[str_pos - 1]))
		|| (!is_sep(g_str[str_pos]) && str_pos == 0))
			word_count++;
		str_pos++;
	}
	return (word_count);
}

int		*len_of_word(int word_n)
{
	int		str_pos;
	int		word_pos;
	int		len_count;
	int		*word_len_arr;

	word_len_arr = (int*)malloc(sizeof(int) * word_n);
	len_count = 0;
	word_pos = 0;
	str_pos = 0;
	while (g_str[str_pos] != '\0')
	{
		if (!is_sep(g_str[str_pos]))
		{
			len_count++;
			word_len_arr[word_pos] = len_count;
		}
		else if (str_pos > 0 && !is_sep(g_str[str_pos - 1]))
		{
			word_pos++;
			len_count = 0;
		}
		str_pos++;
	}
	return (word_len_arr);
}

char	**mk_word(char **mk_strs, int *word_len_arr, int word_n)
{
	int		n;
	int		word_order;
	int		word_pos;

	n = -1;
	while (++n < word_n)
	{
		mk_strs[n] = (char*)malloc(sizeof(char) * word_len_arr[n] + 1);
		mk_strs[n][word_len_arr[n]] = '\0';
	}
	n = -1;
	word_order = 0;
	word_pos = 0;
	while (g_str[++n] != '\0')
	{
		if (!is_sep(g_str[n]))
			mk_strs[word_order][word_pos++] = g_str[n];
		else if (!is_sep(g_str[n - 1]) && n > 0)
		{
			word_pos = 0;
			word_order++;
		}
	}
	return (mk_strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**mk_strs;
	int		*word_len_arr;
	int		word_n;

	g_str = str;
	g_sep = charset;
	word_n = count_of_word();
	word_len_arr = len_of_word(word_n);
	mk_strs = (char**)malloc(sizeof(char*) * (word_n + 1));
	mk_strs[word_n] = NULL;
	mk_strs = mk_word(mk_strs, word_len_arr, word_n);
	return (mk_strs);
}
