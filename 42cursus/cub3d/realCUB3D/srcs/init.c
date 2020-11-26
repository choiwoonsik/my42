/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:19:23 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 12:21:15 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			mini_value_init(t_info *info)
{
	info->player.pos_x = 3.0;
	info->player.pos_y = 3.0;
	info->player.dir_x = -1.0;
	info->player.dir_y = 0.0;
	info->player.cam_x = 0.0;
	info->player.cam_y = 0.66;
	info->config.move_speed = M_PI_4 / 3;
	info->config.rot_speed = M_PI_4 / 3;
}

int				mini_config_init(t_info *info)
{
	int		i;

	i = -1;
	info->config.cl_color = 0;
	info->config.fl_color = 0;
	info->config.map_height = 0;
	info->config.map_width = 0;
	info->config.screen_height = 0;
	info->config.screen_width = 0;
	info->config.world_map = NULL;
	while (++i < 8)
	{
		info->config.tex = (t_tex *)malloc(sizeof(t_tex) * 8);
		info->config.tex[i].tex_path = NULL;
		info->config.tex[i].texture = NULL;
		info->config.tex[i].tex_height = 0;
		info->config.tex[i].tex_width = 0;
	}
	return (TRUE);
}

void			mini_screen_init(t_info *info)
{
	int		i;
	int		j;

	info->config.screen_buffer =
			(int **)malloc(sizeof(int *) * info->config.screen_height);
	i = -1;
	while (++i < info->config.screen_height)
	{
		info->config.screen_buffer[i] =
			(int *)malloc(sizeof(int) * info->config.screen_width);
	}
	i = -1;
	while (++i < info->config.screen_height)
	{
		j = -1;
		while (++j < info->config.screen_width)
			info->config.screen_buffer[i][j] = 0;
	}
}

void			mini_init(t_info *info, t_config *conf)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, conf->screen_width
								, conf->screen_height, "cub3d");
	info->img.img = mlx_new_image(info->mlx
								, conf->screen_width, conf->screen_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
	&info->img.bits_per_pixel, &info->img.size_line, &info->img.endian);
}

void			f_free(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->config.map_height)
	{
		if (info->config.world_map[i])
			free(info->config.world_map[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (info->config.tex[i].texture)
		{
			free(info->config.tex[i].texture);
			info->config.tex[i].texture = NULL;
		}
		i++;
	}
	free(info->config.tex);
}
