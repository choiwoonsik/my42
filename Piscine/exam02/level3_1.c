/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level3_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:44:29 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/18 16:50:05 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	is_first(char c, char *word_arr)
{
	return word_arr[(unsigned)c];
}

void	set_not_first(char c, char *arr)
{
	arr[(unsigned)c] = 0;
}

void	inter(char	*str1, char *str2)
{
	char	all[255];
	int		i;
	int		j;

	i = 0;
	while (all[i] != '\0')
		all[i] = 1;
	i = 0;
	while (str1[])
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
}
