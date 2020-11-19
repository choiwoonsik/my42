/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:31:29 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/18 23:18:00 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_screen_size(t_info *info, char *line)
{
	int		i;
	int		width;
	int		height;

	i = 0;
	width = 0;
	height = 0;
	while (is_upper(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	while (is_digit(line[i]))
	{
		width = width * 10 + line[i] - '0';
		i++;
	}
	while (is_space(line[i]))
		i++;
	while (is_digit(line[i]))
	{
		height = height * 10 + line[i] - '0';
		i++;
	}
	info->config.screenWidth = width;
	info->config.screenHeight = height;
	printf("sc width : %d, sc height : %d\n", width, height);
	return (TRUE);
}

char		*parse_path(char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (is_upper(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	path = ft_strdup(line + i);
	printf("path : %s\n", path);
	return (path);
}

int			parse_color(char *line)
{
	int		color;
	int		colors[3];
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 3)
		colors[i] = 0;
	i = 0;
	while (is_upper(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	while (++j < 3 && line[i])
	{
		while (line[i] && ft_isdigit(line[i]))
			colors[j] = colors[j] * 10 + line[i++] - '0';
		if ((!ft_strchr(",", line[i]) && line[i] != '\0') || colors[j] > 255)
			return (FALSE);
		if (ft_strchr(",", line[i]))
			i++;
	}
	color = colors[0] * 256 * 256 + colors[1] * 256 + colors[2];
	printf("fl color : %d\n", color);
	return (color);
}

int			parse_map(t_config *conf, char *line)
{
	int		i;
	int		j;
	char	**buf_map;

	if (!(buf_map = ft_split(line, '\n')))
		return (FALSE);
	free(line);
	i = -1;
	j = 0;
	while (buf_map[++i])
		j = j < (int)ft_strlen(buf_map[i]) ?
		(int)ft_strlen(buf_map[i]) : j;
	conf->mapHeight = i;
	conf->mapWidth = j;
	i = -1;
	conf->worldMap = (char **)malloc(sizeof (char *) * conf->mapHeight);
	while (++i < conf->mapHeight)
	{
		conf->worldMap[i] = (char *)malloc(sizeof (char) * conf->mapWidth);
		j = -1;
		while (++j < conf->mapWidth)
			conf->worldMap[i][j] = buf_map[i][j];
	}
	printf_map(conf->worldMap);
	return (TRUE);
}

int			parse_by_type(t_info *info, char *line, int ret, int type)
{
	static char		*buffer_map = "";

	printf("type : %d , g_ret : %d\n", type, ret);
	if (type == cub_R)
	{
		if (!parse_screen_size(info, line))
		{
			printf("screen size error");
			return (free_line(line, FALSE));
		}
	}
	else if (type >= cub_NO && type <= cub_S)
	{
		if (info->config.tex[type].texPath
		|| !(info->config.tex[type].texPath = parse_path(line)))
		{
			printf("texPath error");
			return (free_line(line, FALSE));
		}
	}
	else if (type == cub_FL || type == cub_CL)
	{
		if (type == cub_FL && !(info->config.fl_color = parse_color(line)))
		{
			printf("fl color error");
			return (free_line(line, FALSE));
		}
		else if (type == cub_CL && !(info->config.cl_color = parse_color(line)))
		{
			printf("cl color error");
			return (free_line(line, FALSE));
		}
	}
	else
	{
		buffer_map = update_map(buffer_map, line);
		printf("%d : update...%s\n", ret, buffer_map);
		if (ret == 0 && !parse_map(&info->config, buffer_map))
		{
			printf("update map error");
			return (free_line(line, FALSE));
		}
	}
	return (free_line(line, TRUE));
}