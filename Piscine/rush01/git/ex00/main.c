/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swpark <seongwop@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 13:13:27 by swpark            #+#    #+#             */
/*   Updated: 2020/06/06 23:59:18 by swpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocation.h"
#include "print.h"
#include "check.h"

int	**g_map;

int		ft_print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		ft_check_previous_col(int x, int y, int element)
{
	int idx;

	idx = 0;
	while (idx < x)
	{
		if (g_map[idx][y] == element)
			return (1);
		idx++;
	}
	return (0);
}

int		ft_check_previous_row(int x, int y, int element)
{
	int idx;

	idx = 0;
	while (idx < y)
	{
		if (g_map[x][idx] == element)
			return (1);
		idx++;
	}
	return (0);
}

int		ft_set_permutation(int *num_sight, int map_size, int x, int y)
{
	int idx;

	if (y == map_size)
	{
		if (ft_check_left(g_map, num_sight, map_size, x) ||
			ft_check_right(g_map, num_sight, map_size, x))
			return (1);
		x++;
		y = 0;
		if (x == map_size)
			return (ft_check_up(g_map, num_sight, map_size) ||
					ft_check_down(g_map, num_sight, map_size));
	}
	idx = 0;
	while (++idx <= map_size)
	{
		if (ft_check_previous_col(x, y, idx) ||
			ft_check_previous_row(x, y, idx))
			continue ;
		g_map[x][y] = idx;
		if (!ft_set_permutation(num_sight, map_size, x, y + 1))
			return (0);
		g_map[x][y] = 0;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int *num_sight;
	int	map_size;

	if (argc <= 1)
		return (ft_print_error());
	num_sight = NULL;
	num_sight = ft_init_num_sight(argv, num_sight);
	map_size = ft_parse_input(argv, num_sight);
	if (map_size < 1)
		return (ft_print_error());
	g_map = ft_init_map(g_map, map_size);
	if (ft_set_permutation(num_sight, map_size, 0, 0))
		ft_print_error();
	else
		ft_print_map(g_map, map_size);
	ft_del_map(g_map);
	return (0);
}
