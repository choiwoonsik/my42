/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swpark <seongwop@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:08:53 by swpark            #+#    #+#             */
/*   Updated: 2020/06/06 23:11:27 by swpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "check.h"

int		ft_check_left(int **map, int *num_sight, int map_size, int row)
{
	int idx;
	int max;
	int ret;

	idx = 0;
	max = 0;
	ret = 0;
	while (idx < map_size)
	{
		if (map[row][idx] > max)
		{
			max = map[row][idx];
			ret++;
		}
		idx++;
	}
	if (num_sight[map_size * 2 + row] != ret)
		return (1);
	return (0);
}

int		ft_check_right(int **map, int *num_sight, int map_size, int row)
{
	int idx;
	int max;
	int ret;

	idx = map_size - 1;
	max = 0;
	ret = 0;
	while (idx >= 0)
	{
		if (map[row][idx] > max)
		{
			max = map[row][idx];
			ret++;
		}
		idx--;
	}
	if (num_sight[map_size * 3 + row] != ret)
		return (1);
	return (0);
}

int		ft_check_up(int **map, int *num_sight, int map_size)
{
	int idx;
	int max;
	int ret;
	int col;

	col = 0;
	while (col < map_size)
	{
		idx = -1;
		max = 0;
		ret = 0;
		while (++idx < map_size)
		{
			if (map[idx][col] > max)
			{
				max = map[idx][col];
				ret++;
			}
		}
		if (num_sight[col] != ret)
			return (1);
		col++;
	}
	return (0);
}

int		ft_check_down(int **map, int *num_sight, int map_size)
{
	int idx;
	int max;
	int ret;
	int col;

	col = 0;
	while (col < map_size)
	{
		idx = map_size;
		max = 0;
		ret = 0;
		while (--idx >= 0)
		{
			if (map[idx][col] > max)
			{
				max = map[idx][col];
				ret++;
			}
		}
		if (num_sight[map_size + col] != ret)
			return (1);
		col++;
	}
	return (0);
}
