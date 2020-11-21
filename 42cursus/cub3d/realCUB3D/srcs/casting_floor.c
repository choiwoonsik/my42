/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:24:40 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/17 21:27:25 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_floor(int y, t_floor *fl, t_player *p, t_config *conf)
{
	fl->rayDirX0 = p->dirX - p->camX;
	fl->rayDirY0 = p->dirY - p->camY;
	fl->rayDirX1 = p->dirX + p->camX;
	fl->rayDirY1 = p->dirY + p->camY;

	fl->p = y - (conf->screenHeight / 2);
	fl->posZ = conf->screenHeight * 0.5;

	fl->rowDist = fl->posZ / fl->p;

	fl->floorStepX = fl->rowDist * (fl->rayDirX1 - fl->rayDirX0) / conf->screenWidth;
	fl->floorStepY = fl->rowDist * (fl->rayDirY1 - fl->rayDirY0) / conf->screenWidth;

	fl->floorX = p->posX + (fl->rowDist * fl->rayDirX0);
	fl->floorY = p->posY + (fl->rowDist * fl->rayDirY0);
}

void		build_floor(int	y, int x, t_floor *fl, t_info *info, t_config *conf)
{
	fl->color = conf->fl_color;
	info->config.screenBuffer[y][x] = fl->color;

	fl->color = conf->cl_color;
	info->config.screenBuffer[conf->screenHeight - y - 1][x] = fl->color;
}

void		casting_floor(t_info *info)
{
	int			y;
	int			x;
	t_floor		fl;

	y = -1;
	while (++y < info->config.screenHeight)
	{
		init_floor(y, &fl, &info->player, &info->config);
		x = -1;
		while (++x < info->config.screenWidth)
		{
			build_floor(y, x, &fl, info, &info->config);
		}
	}
}