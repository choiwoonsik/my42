/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skweon <skweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:17:44 by skweon            #+#    #+#             */
/*   Updated: 2020/06/18 03:29:06 by skweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "all.h"

t_info			*read_map(char *file_name)
{
	t_info		*map_info;
	char		**lines;

	if ((lines = read_file(file_name)) == 0)
		return (0);
	if ((map_info = parse_map_info(lines[0])) == 0)
	{
		free_strs(lines, 0);
		return (0);
	}
	if ((map_info->map = get_map(lines + 1)) == 0)
	{
		free_map_info(map_info);
		free_strs(lines, 0);
		return (0);
	}
	free(lines[0]);
	free(lines);
	return (map_info);
}

char			**get_map(char **lines)
{
	char		**map;
	int			i;

	i = 0;
	while (lines[i])
		i++;
	if ((map = (char **)malloc(sizeof(char *) * (i + 1))) == 0)
		return (0);
	i = 0;
	while (lines[i])
	{
		map[i] = lines[i];
		i++;
	}
	map[i] = 0;
	return (map);
}

t_info			*parse_map_info(char *info)
{
	t_info		*map_info;
	int			len;

	len = 0;
	while (info[len])
		len++;
	if (len < 4)
		return (0);
	if ((map_info = (t_info *)malloc(sizeof(t_info))) == 0)
		return (0);
	map_info->mark = info[--len];
	map_info->obs = info[--len];
	map_info->blank = info[--len];
	info[len] = 0;
	map_info->line_num = ft_atoi(info);
	map_info->map = 0;
	return (map_info);
}

void			free_map_info(t_info *map_info)
{
	free_strs(map_info->map, 0);
	free(map_info);
}
