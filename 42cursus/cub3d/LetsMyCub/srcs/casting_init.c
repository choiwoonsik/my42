/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:08:40 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/19 11:46:02 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		cast_wall_init(t_info *info, t_config *conf, int x)
{
	info->cast.cameraX = (2 * x / (double)conf->screenWidth) - 1; //-1 ~ 1
	// printf("camera X : %f, dir X : %f, cam X : %f, x : %x\n", info->cast.cameraX, info->player.dirX, info->player.camX, x);
	// printf("camera X : %f, dir Y : %f, cam Y : %f\n", info->cast.cameraX, info->player.dirY, info->player.camY);
	info->cast.rayDirX = info->player.dirX + (info->player.camX * info->cast.cameraX);
	info->cast.rayDirY = info->player.dirY + (info->player.camY * info->cast.cameraX);

	info->cast.mapX = (int)info->player.posX;
	info->cast.mapY = (int)info->player.posY;
	info->cast.deltaDistX = fabs(1 / info->cast.rayDirX);
	info->cast.deltaDistY = fabs(1 / info->cast.rayDirY);
	printf("x > %d >> ray X : %f, ray Y : %f\n", x, info->cast.rayDirX, info->cast.rayDirY);
	printf("Del X : %f, Del Y : %f\n", info->cast.deltaDistX, info->cast.deltaDistY);
	info->cast.hit = 0;
}

void		dda_init(t_dda *dda, t_cast *cast, t_config *conf, t_player *p)
{
	//printf("screen H : %d, perpDist : %f\n", conf->screenHeight, cast->perpwallDist);
	dda->lineHeight = (int)(conf->screenHeight / cast->perpwallDist);
	dda->drawSt = (-dda->lineHeight / 2) + conf->screenHeight / 2;
	dda->drawEd = (dda->lineHeight / 2) + conf->screenHeight / 2;
	if (dda->drawSt < 0)
		dda->drawSt = 0;
	if (dda->drawEd >= conf->screenHeight)
		dda->drawEd = conf->screenHeight - 1;
	dda->texN = conf->worldMap[cast->mapX][cast->mapY];

	if (cast->side == 0)
		dda->wallX = p->posY + cast->perpwallDist * cast->rayDirY;
	else
		dda->wallX = p->posX + cast->perpwallDist * cast->rayDirX;
	dda->wallX -= floor(dda->wallX);
	dda->texX = (int)(dda->wallX * (double)conf->tex[1].texWidth);
	if ((cast->side == 0 && cast->rayDirX > 0)
	|| (cast->side == 1 && cast->rayDirY < 0))
		dda->texX = conf->tex[1].texWidth - dda->texX - 1;
}