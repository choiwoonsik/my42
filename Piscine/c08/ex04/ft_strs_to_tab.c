/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 21:49:05 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/13 09:13:29 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char					*copy_str(char *str)
{
	char	*copy_arr;
	int		word;

	word = 0;
	copy_arr = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!copy_arr)
		return (0);
	while (str[word] != '\0')
	{
		copy_arr[word] = str[word];
		word++;
	}
	copy_arr[word] = '\0';
	return (copy_arr);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str				*arr;
	int						idx;

	idx = 0;
	arr = (struct s_stock_str*)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!arr)
		return (0);
	while (idx < ac)
	{
		arr[idx].size = ft_strlen(av[idx]);
		arr[idx].str = av[idx];
		arr[idx].copy = copy_str(av[idx]);
		idx++;
	}
	arr[idx].str = 0;
	return (arr);
}
