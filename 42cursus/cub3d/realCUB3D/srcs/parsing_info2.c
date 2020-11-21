/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:31:29 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/20 21:44:38 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		copy_to_original(t_config *conf, char **buf_map)
{
	int		i;
	int		j;

	i = -1;
	conf->worldMap = (char **)malloc(sizeof (char *)
						* (conf->mapHeight + 1));
	while (++i < conf->mapHeight)
	{
		conf->worldMap[i] = (char *)malloc(sizeof (char)
							* (conf->mapWidth + 1));
		j = -1;
		while (++j < conf->mapWidth)
			conf->worldMap[i][j] = buf_map[i][j];
		conf->worldMap[i][j] = '\0';
	}
	conf->worldMap[i] = NULL;
}

int			parse_map(t_config *conf, char *line)
{
	int				i;
	int				j;
	static char		**buf_map;

	i = -1;
	j = 0;
	buf_map = NULL;
	if (!(buf_map = ft_split(line, '\n')))
		return (FALSE);
	free(line);
	while (buf_map[++i])
		j = j < (int)ft_strlen(buf_map[i]) ?
		(int)ft_strlen(buf_map[i]) : j;
	conf->mapHeight = i;
	conf->mapWidth = j;

	copy_to_original(conf, buf_map);
	return (TRUE);
}

int			parse_type_RNSFC(int type, t_info *info, char *line, t_config *conf)
{
	if (type == cub_R)
	{
		if (!parse_screen_size(info, line))
			return (free_line(line, FALSE));
	}
	else if (type >= cub_EA && type <= cub_S)
	{
		if (conf->tex[type].texPath
		|| !(conf->tex[type].texPath = parse_path(line)))
			return (free_line(line, FALSE));
	}
	else if (type == cub_FL || type == cub_CL)
	{
		if (type == cub_FL && !(conf->fl_color = parse_color(line)))
			return (free_line(line, FALSE));
		if (type == cub_CL && !(conf->cl_color = parse_color(line)))
			return (free_line(line, FALSE));
	}
	return (TRUE);
}

int			parse_by_type(t_info *info, char *line, int ret, int type)
{
	static char		*buffer_map = "";

	if (type <= 7 && type >= 0)
	{
		if (!(parse_type_RNSFC(type, info, line, &info->config)))
			return (ERROR_MESSAGE(info, FALSE, "error RNSCF"));
	}
	else if (type == 10)
	{
		buffer_map = update_map(buffer_map, line);
		if (ret == 0 && !parse_map(&info->config, buffer_map))
		{
			return (free_line(line, FALSE));
		}
	}
	return (free_line(line, TRUE));
}