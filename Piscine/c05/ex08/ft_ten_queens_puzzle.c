/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 20:39:24 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/06 22:31:15 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int *chess)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = chess[i] + '0';
		write(1, &c, 1);
		i++;
	}
	c = '\n';
	write(1, &c, 1);
}

int		possible_chess(int level, int *chess)
{
	int		row;

	row = 0;
	while (row < level)
	{
		if (chess[row] == chess[level]
		|| chess[row] == chess[level] + (level - row)
		|| chess[row] == chess[level] - (level - row))
			return (0);
		row++;
	}
	return (1);
}

void	recursive_chess(int level, int *chess, int *count)
{
	int		pos;

	if (level == 10)
	{
		(*count)++;
		print(chess);
	}
	else
	{
		pos = 0;
		while (pos < 10)
		{
			chess[level] = pos;
			if (possible_chess(level, chess))
			{
				recursive_chess(level + 1, chess, count);
			}
			pos++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		chess[10];
	int		count;

	count = 0;
	recursive_chess(0, chess, &count);
	return (count);
}
