/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:39:04 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 17:01:05 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			count_sprite(t_config *conf, t_sp *sp)
{
	int		x;
	int		y;

	x = -1;
	while (++x < conf->map_height)
	{
		y = -1;
		while (conf->world_map[x][++y])
		{
			if (conf->world_map[x][y] == '2')
			{
				sp->sp_arr[sp->count].x = x;
				sp->sp_arr[sp->count].y = y;
				sp->count++;
			}
		}
	}
}

int				sprite_init(t_info *info, t_sp *sp)
{
	sp->count = 0;
	if (!(sp->sp_arr = (t_pos *)malloc(sizeof(t_pos)
			* (info->config.map_height * info->config.map_width))))
		return (error_message(info, FALSE, "error alloc"));
	count_sprite(&info->config, sp);
	if (!(sp->z_buffer = (double *)malloc(sizeof(double)
						* (info->config.screen_width + 1))))
		return (error_message(info, FALSE, "error alloc"));
	sp->z_buffer[info->config.screen_width] = '\0';
	if (!(sp->sp_order = (int *)malloc(sizeof(int) * sp->count)))
		return (error_message(info, FALSE, "error alloc"));
	if (!(sp->sp_dis = (double *)malloc(sizeof(double) * sp->count)))
		return (error_message(info, FALSE, "error alloc"));
	return (TRUE);
}
