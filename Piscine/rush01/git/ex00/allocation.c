/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swpark <seongwop@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:08:01 by swpark            #+#    #+#             */
/*   Updated: 2020/06/07 00:01:43 by swpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"

int		*ft_init_num_sight(char *argv[], int *num_sight)
{
	int idx;
	int size;

	idx = 0;
	while (argv[1][idx])
		idx++;
	size = (idx + 1) / 2;
	num_sight = (int*)malloc(sizeof(int) * size);
	idx = 0;
	while (idx < size)
		num_sight[idx++] = 0;
	return (num_sight);
}

int		**ft_init_map(int **map, int map_size)
{
	int idx;
	int idx_y;

	idx = 0;
	map = (int**)malloc(sizeof(int*) * map_size);
	while (idx < map_size)
	{
		map[idx] = (int*)malloc(sizeof(int) * map_size);
		idx_y = 0;
		while (idx_y < map_size)
		{
			map[idx][idx_y] = 0;
			idx_y++;
		}
		idx++;
	}
	return (map);
}

int		**ft_del_map(int **map)
{
	free(map);
	return (map);
}

int		ft_parse_input(char *argv[], int *num_sight)
{
	int idx;
	int num;
	int map_size;

	map_size = 0;
	idx = 0;
	num = 0;
	while (argv[1][idx])
	{
		if (argv[1][idx] == ' ')
		{
			num_sight[map_size++] = num;
			num = 0;
		}
		else
			num = num * 10 + (argv[1][idx] - '0');
		idx++;
	}
	num_sight[map_size++] = num;
	if (map_size > 1 && map_size % 4)
		return (-1);
	map_size /= 4;
	return (map_size);
}
