/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:31:29 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/27 18:26:23 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		copy_to_original(t_config *conf, char **buf_map)
{
	int				i;
	int				j;

	i = -1;
	conf->world_map = (char **)malloc(sizeof(char *)
						* (conf->map_height + 1));
	while (++i < conf->map_height)
	{
		conf->world_map[i] = (char *)malloc(sizeof(char)
							* (conf->map_width + 1));
		j = -1;
		while (buf_map[i][++j])
			conf->world_map[i][j] = buf_map[i][j];
		conf->world_map[i][j] = '\0';
	}
	conf->world_map[i] = NULL;
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
	conf->map_height = i;
	conf->map_width = j;
	copy_to_original(conf, buf_map);
	return (TRUE);
}

int			check_type(int type, t_info *info, char *line, t_config *conf)
{
	if (type == CUB_R)
	{
		if (info->config.screen_width > 0
		|| info->config.screen_height > 0
		|| !parse_screen_size(info, line))
			return (free_line(line, FALSE));
	}
	else if (type >= CUB_EA && type <= CUB_S)
	{
		if (conf->tex[type].tex_path || ft_strncmp(line + ft_strlen(line)
		- 4, ".xpm", 4) || !(conf->tex[type].tex_path = parse_path(line)))
			return (free_line(line, FALSE));
	}
	else if (type == CUB_FL && (conf->fl_color > 0
		|| !(conf->fl_color = parse_color(line))))
		return (free_line(line, FALSE));
	else if (type == CUB_CL && (conf->cl_color > 0
		|| !(conf->cl_color = parse_color(line))))
		return (free_line(line, FALSE));
	return (TRUE);
}

int			parse_by_type(t_info *info, char *line, int ret, int type)
{
	static char		*buffer_map = "";

	if (type <= CUB_R && type >= CUB_EA)
	{
		if (!(check_type(type, info, line, &info->config)))
			return (error_message(info, FALSE, "error RNSEWCF"));
	}
	else if (type == CUB_MAP)
	{
		buffer_map = update_map(buffer_map, line);
		if (ret == 0 && !parse_map(&info->config, buffer_map))
		{
			return (free_line(line, FALSE));
		}
	}
	return (free_line(line, TRUE));
}
