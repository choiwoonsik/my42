/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:08:40 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 12:21:15 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		cast_wall_init(t_info *info, t_config *conf, int x)
{
	info->cast.camera_x = (2 * x / (double)conf->screen_width) - 1;
	info->cast.ray_dirx = info->player.dir_x
						+ (info->player.cam_x * info->cast.camera_x);
	info->cast.ray_diry = info->player.dir_y
						+ (info->player.cam_y * info->cast.camera_x);
	info->cast.map_x = (int)info->player.pos_x;
	info->cast.map_y = (int)info->player.pos_y;
	info->cast.del_dist_x = fabs(1 / info->cast.ray_dirx);
	info->cast.del_dist_y = fabs(1 / info->cast.ray_diry);
	info->cast.hit = 0;
}

void		dda_init(t_dda *dda, t_cast *cast, t_config *conf, t_player *p)
{
	dda->line_height = (int)(conf->screen_height / cast->perp_wall_d);
	dda->draw_st = (-dda->line_height / 2) + conf->screen_height / 2;
	dda->draw_ed = (dda->line_height / 2) + conf->screen_height / 2;
	if (dda->draw_st < 0)
		dda->draw_st = 0;
	if (dda->draw_ed >= conf->screen_height)
		dda->draw_ed = conf->screen_height - 1;
	dda->tex_n = conf->world_map[cast->map_x][cast->map_y] - '0';
	if (cast->side == 0)
		dda->wall_x = p->pos_y + cast->perp_wall_d * cast->ray_diry;
	else
		dda->wall_x = p->pos_x + cast->perp_wall_d * cast->ray_dirx;
	dda->wall_x -= floor(dda->wall_x);
	dda->tex_x = (int)(dda->wall_x * (double)conf->tex[dda->tex_n].tex_width);
	if ((cast->side == 0 && cast->ray_dirx > 0)
	|| (cast->side == 1 && cast->ray_diry < 0))
		dda->tex_x = conf->tex[dda->tex_n].tex_width - dda->tex_x - 1;
}
