/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:39:45 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/17 21:51:07 by wchoi            ###   ########.fr       */
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

void		calc(t_info *info)
{
	casting_floor(info);
	casting_wall(info, &info->config);
}

int			main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}