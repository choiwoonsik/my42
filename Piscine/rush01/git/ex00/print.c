/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swpark <seongwop@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 13:14:25 by swpark            #+#    #+#             */
/*   Updated: 2020/06/06 21:15:21 by swpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_print_map(int **map, int map_size)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < map_size)
	{
		y = 0;
		while (y < map_size)
		{
			c = map[x][y] + '0';
			write(1, &c, 1);
			if (y != map_size - 1)
				write(1, " ", 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}
