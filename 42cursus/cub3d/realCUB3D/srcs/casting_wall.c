/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:09:38 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 12:56:34 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		calc_side_dist(t_info *info)
{
	if (info->cast.ray_dirx < 0)
	{
		info->cast.step_x = -1;
		info->cast.side_dist_x =
		(info->player.pos_x - info->cast.map_x) * info->cast.del_dist_x;
	}
	else
	{
		info->cast.step_x = 1;
		info->cast.side_dist_x =
		(info->cast.map_x + 1.0 - info->player.pos_x) * info->cast.del_dist_x;
	}
	if (info->cast.ray_diry < 0)
	{
		info->cast.step_y = -1;
		info->cast.side_dist_y =
		(info->player.pos_y - info->cast.map_y) * info->cast.del_dist_y;
	}
	else
	{
		info->cast.step_y = 1;
		info->cast.side_dist_y =
		(info->cast.map_y + 1.0 - info->player.pos_y) * info->cast.del_dist_y;
	}
}

void		calc_dda(t_cast *cast, t_info *info)
{
	while (cast->hit == 0)
	{
		if (cast->side_dist_x < cast->side_dist_y)
		{
			cast->side_dist_x += cast->del_dist_x;
			cast->map_x += cast->step_x;
			cast->side = 0;
		}
		else
		{
			cast->side_dist_y += cast->del_dist_y;
			cast->map_y += cast->step_y;
			cast->side = 1;
		}
		if (info->config.world_map[cast->map_x][cast->map_y] - '0' == 1)
			cast->hit = 1;
	}
	if (cast->side == 0)
		cast->perp_wall_d = (cast->map_x - info->player.pos_x +
		(1 - cast->step_x) / 2) / cast->ray_dirx;
	else
		cast->perp_wall_d = (cast->map_y - info->player.pos_y +
		(1 - cast->step_y) / 2) / cast->ray_diry;
}

void		calc_wall_height(t_cast *cast, t_dda *dda, t_config *conf, int x)
{
	int		d_y;
	int		tex_y;
	int		color;
	int		tex_height;

	tex_height = conf->tex[dda->tex_n].tex_height;
	dda->step = 1.0 * tex_height / dda->line_height;
	dda->tex_pos = (dda->draw_st - conf->screen_height / 2 +
					dda->line_height / 2) * dda->step;
	d_y = dda->draw_st;
	while (d_y < dda->draw_ed)
	{
		tex_y = (int)dda->tex_pos & (tex_height - 1);
		dda->tex_pos += dda->step;
		if (cast->side == 1 && dda->tex_n != 4)
			dda->tex_n = cast->ray_diry < 0 ? CUB_WE : CUB_EA;
		else if (cast->side == 0 && dda->tex_n != 4)
			dda->tex_n = cast->ray_dirx < 0 ? CUB_NO : CUB_SO;
		color = conf->tex[dda->tex_n].texture[tex_height * tex_y + dda->tex_x];
		conf->screen_buffer[d_y][x] = color;
		d_y++;
	}
}

void		casting_wall(t_info *info, t_config *conf, t_sp *sp)
{
	int		x;

	x = 0;
	while (x < conf->screen_width)
	{
		cast_wall_init(info, &info->config, x);
		calc_side_dist(info);
		calc_dda(&info->cast, info);
		dda_init(&info->dda, &info->cast, &info->config, &info->player);
		calc_wall_height(&info->cast, &info->dda, &info->config, x);
		sp->z_buffer[x] = info->cast.perp_wall_d;
		x++;
	}
}
