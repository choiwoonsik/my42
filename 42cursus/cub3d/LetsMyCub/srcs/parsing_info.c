/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:14 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/17 11:26:50 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			g_fd;
int			g_ret;

static int			isCubFile(char *path)
{
	int		len;
	int		check;

	len = ft_strlen(path);
	check = 1;
	if (len >= 4)
		check = ft_strncmp(path + len - 4, ".cub", 4);
	if (check == 0)
		return (TRUE);
	return (FALSE);
}

static int			isMap(char *line)
{
	int		pos;

	pos = 0;
	while (line[pos])
	{
		if (ft_strchr("012S", line[pos]))
			pos++;
		else
			return (FALSE);
	}
	return (TRUE);
}

static int			check_line_type(char *line)
{
	printf("%c%c\n", line[0], line[1]);
	if (line[0] == 'R' && line[1] == ' ')
		return (cub_R);
	else if (line[0] == 'N' && line[1] == 'O')
		return (cub_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (cub_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (cub_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (cub_EA);
	else if (line[0] == 'S' && line[1] == ' ')
		return (cub_S);
	else if (line[0] == 'F' && line[1] == ' ')
		return (cub_FL);
	else if (line[0] == 'C' && line[1] == ' ')
		return (cub_CL);
	else if (isMap(line))
		return (cub_MAP);
	return (-1);
}

static int			is_blank_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			parse_info(t_info *info, char *path)
{
	int		type;
	char	*line;

	if (!isCubFile(path))
		return (ERROR_MESSAGE(info, FALSE, "wrong file"));
	if ((g_fd = open(path, O_RDONLY)) < 0)
		return (ERROR_MESSAGE(info, FALSE, "wrong path"));
	g_ret = 1;
	while ((g_ret = get_next_line(g_fd, &line)) > 0)
	{
		printf("==start==\n");
		if ((type = check_line_type(line)) == -1)
			return (ERROR_MESSAGE(info, FALSE, "check type error"));

		printf(">> %d\n", g_ret);
		if (is_blank_line(line) && !info->config.worldMap)
		{
			free(line);
			continue;
		}
		else if (is_blank_line(line) && info->config.worldMap && g_ret)
			return (ERROR_MESSAGE(info, FALSE, "blank line error"));

		if (!(parse_by_type(info, line, g_ret, type)))
			return (0);
	}
	parse_by_type(info, line, g_ret, type);
	close(g_fd);
	printf("천장 색 : %d\n", info->config.cl_color);
	printf("바닥 색 : %d\n", info->config.fl_color);
	printf("맵 높이 : %d\n", info->config.mapHeight);
	printf("맵 폭 : %d\n", info->config.mapWidth);
	printf("스크린 높이 : %d\n", info->config.screenHeight);
	printf("스크린 폭 : %d\n", info->config.screenWidth);
	return (TRUE);
}