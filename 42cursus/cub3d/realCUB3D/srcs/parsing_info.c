/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:14 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 12:59:34 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int					g_fd;
int					g_ret;

static int			is_cubfile(char *path)
{
	int				len;
	int				check;

	len = ft_strlen(path);
	check = 1;
	if (len >= 4)
		check = ft_strncmp(path + len - 4, ".cub", 4);
	if (check == 0)
		return (TRUE);
	return (FALSE);
}

static int			is_map(char *line)
{
	int				pos;

	pos = 0;
	while (line[pos])
	{
		if (ft_strchr("012NSEW ", line[pos]))
			pos++;
		else
			return (FALSE);
	}
	return (TRUE);
}

static int			check_line_type(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (CUB_R);
	else if (line[0] == 'N' && line[1] == 'O')
		return (CUB_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (CUB_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (CUB_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (CUB_EA);
	else if (line[0] == 'S' && line[1] == ' ')
		return (CUB_S);
	else if (line[0] == 'F' && line[1] == ' ')
		return (CUB_FL);
	else if (line[0] == 'C' && line[1] == ' ')
		return (CUB_CL);
	else if (is_map(line))
		return (CUB_MAP);
	return (-1);
}

static int			is_blank_line(char *line)
{
	int				i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int					parse_info(t_info *info, char *path)
{
	int				type;
	char			*line;

	if (!is_cubfile(path))
		return (error_message(info, FALSE, "wrong file"));
	if ((g_fd = open(path, O_RDONLY)) < 0)
		return (error_message(info, FALSE, "wrong path"));
	g_ret = 1;
	while ((g_ret = get_next_line(g_fd, &line)) > 0)
	{
		if ((type = check_line_type(line)) == -1)
			return (error_message(info, FALSE, "error wrong type"));
		if (is_blank_line(line) && !info->config.world_map)
		{
			free(line);
			continue;
		}
		else if (is_blank_line(line) && info->config.world_map && g_ret)
			return (error_message(info, FALSE, "error blank line"));
		if (!(parse_by_type(info, line, g_ret, type)))
			return (FALSE);
	}
	parse_by_type(info, line, g_ret, type);
	close(g_fd);
	printf("천장 색 : %d\n", info->config.cl_color);
	printf("바닥 색 : %d\n", info->config.fl_color);
	printf("맵 높이 : %d\n", info->config.map_height);
	printf("맵 폭 : %d\n", info->config.map_width);
	printf("스크린 높이 : %d\n", info->config.screen_height);
	printf("스크린 폭 : %d\n", info->config.screen_width);
	return (TRUE);
}
