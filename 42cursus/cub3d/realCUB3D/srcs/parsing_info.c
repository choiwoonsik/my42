/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:14 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/29 17:36:15 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (!ft_strncmp(line, "R ", 2))
		return (CUB_R);
	else if (!ft_strncmp(line, "NO ", 3))
		return (CUB_NO);
	else if (!ft_strncmp(line, "SO ", 3))
		return (CUB_SO);
	else if (!ft_strncmp(line, "WE ", 3))
		return (CUB_WE);
	else if (!ft_strncmp(line, "EA ", 3))
		return (CUB_EA);
	else if (!ft_strncmp(line, "S ", 2))
		return (CUB_S);
	else if (!ft_strncmp(line, "F ", 2))
		return (CUB_FL);
	else if (!ft_strncmp(line, "C ", 2))
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
	return (TRUE);
}
