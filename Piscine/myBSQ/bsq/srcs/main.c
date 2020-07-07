/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:15:26 by skweon            #+#    #+#             */
/*   Updated: 2020/06/18 13:43:46 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "all.h"

char	solve(t_info *map_info)
{
	t_max	*answer;

	if (!is_valid_map(map_info))
	{
		write(1, "map error\n", 10);
		return (1);
	}
	if ((answer = find_largest_square(map_info)) == 0)
		return (-1);
	mark_largest_square(map_info, answer);
	print_max(map_info);
	free(answer);
	return (0);
}

char	read_and_solve(char *file_name)
{
	t_info	*map_info;
	t_info	*(*func)(char *);

	if (file_name == 0)
		func = &read_map_info_from_stdin;
	else
		func = &read_map;
	if ((map_info = func(file_name)) == 0)
	{
		write(2, "map error\n", 10);
		return (-1);
	}
	if (solve(map_info) < 0)
	{
		free_map_info(map_info);
		return (-1);
	}
	free_map_info(map_info);
	return (0);
}

int		main(int argc, char **argv)
{
	int			i;

	if (argc < 2)
	{
		if (read_and_solve(0) != 0)
			return (-1);
		return (0);
	}
	i = 1; 
	while (i < argc)
	{
		if (read_and_solve(argv[i]) != 0)
			return (-1);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
