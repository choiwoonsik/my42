/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:24:40 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 12:21:15 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_floor(int y, t_floor *fl, t_player *p, t_config *conf)
{
	fl->ray_dirx0 = p->dir_x - p->cam_x;
	fl->ray_diry0 = p->dir_y - p->cam_y;
	fl->ray_dirx1 = p->dir_x + p->cam_x;
	fl->ray_diry1 = p->dir_y + p->cam_y;
	fl->p = y - (conf->screen_height / 2);
	fl->pos_z = conf->screen_height * 0.5;
	fl->row_dist = fl->pos_z / fl->p;
	fl->fl_step_x = fl->row_dist *
					(fl->ray_dirx1 - fl->ray_dirx0) / conf->screen_width;
	fl->fl_step_y = fl->row_dist *
					(fl->ray_diry1 - fl->ray_diry0) / conf->screen_width;
	fl->fl_x = p->pos_x + (fl->row_dist * fl->ray_dirx0);
	fl->fl_y = p->pos_y + (fl->row_dist * fl->ray_diry0);
}

void		build_floor(int y, int x, t_floor *fl, t_info *info)
{
	fl->color = info->config.fl_color;
	info->config.screen_buffer[y][x] = fl->color;
	fl->color = info->config.cl_color;
	info->config.screen_buffer
	[info->config.screen_height - y - 1][x] = fl->color;
}

void		casting_floor(t_info *info)
{
	int			y;
	int			x;
	t_floor		fl;

	y = -1;
	while (++y < info->config.screen_height)
	{
		init_floor(y, &fl, &info->player, &info->config);
		x = -1;
		while (++x < info->config.screen_width)
		{
			build_floor(y, x, &fl, info);
		}
	}
}
