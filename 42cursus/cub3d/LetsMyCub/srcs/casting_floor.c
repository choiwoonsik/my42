/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:24:40 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 17:48:52 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_floor(int y, t_floor *fl, t_player *p)
{
	fl->rayDirX0 = p->dirX - p->camX;
	fl->rayDirY0 = p->dirY - p->camY;
	fl->rayDirX1 = p->dirX + p->camX;
	fl->rayDirY1 = p->dirY + p->camY;

	fl->p = y - (screenHeight / 2);
	fl->posZ = screenHeight * 0.5;

	fl->rowDist = fl->posZ / fl->p;

	fl->floorStepX = fl->rowDist * (fl->rayDirX1 - fl->rayDirX0) / screenWidth;
	fl->floorStepY = fl->rowDist * (fl->rayDirY1 - fl->rayDirY0) / screenWidth;

	fl->floorX = p->posX + (fl->rowDist * fl->rayDirX0);
	fl->floorY = p->posY + (fl->rowDist * fl->rayDirY0);
}

void		build_floor(int	y, int x, t_floor *fl, t_info *info)
{
	fl->color = 0x444444;
	info->config.screenBuffer[y][x] = fl->color;

	fl->color = 0xaaaaaa;
	info->config.screenBuffer[screenHeight - y - 1][x] = fl->color;
}

void		casting_floor(t_info *info)
{
	int			y;
	int			x;
	t_floor		fl;

	y = -1;
	while (++y < screenHeight)
	{
		init_floor(y, &fl, &info->player);
		x = -1;
		while (++x < screenWidth)
		{
			build_floor(y, x, &fl, info);
		}
	}
}