/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:39:45 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/24 16:46:58 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw(t_info *info)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->config.screenHeight)
	{
		x = 0;
		while (x < info->config.screenWidth)
		{
			info->img.data[y * info->config.screenWidth + x] =
			info->config.screenBuffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void		calc(t_info *info, t_sp *sp)
{
	casting_floor(info);
	casting_wall(info, &info->config, sp);
	casting_sprite(sp, info);
	calc_sprite(sp, info);
}

int			main_loop(t_info *info)
{
	t_sp	sp;

	if (!(sprite_init(info, &sp)))
		return (ERROR_MESSAGE(info, FALSE, "sprite error"));
	calc(info, &sp);
	draw(info);
	return (0);
}