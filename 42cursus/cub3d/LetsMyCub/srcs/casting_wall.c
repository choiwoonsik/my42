/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:09:38 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/19 11:59:31 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		calc_sideDist(t_info *info)
{
	if (info->cast.rayDirX < 0)
	{
		info->cast.stepX = -1;
		info->cast.sideDistX
		= (info->player.posX - info->cast.mapX) * info->cast.deltaDistX;
	}
	else
	{
		info->cast.stepX = 1;
		info->cast.sideDistX
		= (info->cast.mapX + 1.0 - info->player.posX) * info->cast.deltaDistX;
	}
	if (info->cast.rayDirY < 0)
	{
		info->cast.stepY = -1;
		info->cast.sideDistY
		= (info->player.posY - info->cast.mapY) * info->cast.deltaDistY;
	}
	else
	{
		info->cast.stepY = 1;
		info->cast.sideDistY
		= (info->cast.mapY + 1.0 - info->player.posY) * info->cast.deltaDistY;
	}
	// printf("ray X : %f\n", info->cast.rayDirX);
}

void		calc_dda(t_cast *cast, t_info *info)
{
	int i = 0;
	while (cast->hit == 0)
	{
		i++;
		// printf("sideD X : %f, sideD Y : %f, del X : %f, del Y : %f, Hit : %d\n", 
		// 	cast->sideDistX, cast->sideDistY, cast->deltaDistX, cast->deltaDistY, cast->hit);
		printf("i : %d >>> map X : %d, step X : %d ", i, cast->mapX, cast->stepX);
		printf("side X : %f, side Y : %f\n", cast->sideDistX, cast->sideDistY);
		if (cast->sideDistX < cast->sideDistY)
		{
			cast->sideDistX += cast->deltaDistX;
			cast->mapX += cast->stepX;
			cast->side = 0;
		}
		else
		{
			cast->sideDistY += cast->deltaDistY;
			cast->mapY += cast->stepY;
			cast->side = 1;
		}
		if (info->config.worldMap[cast->mapX][cast->mapY] - '0' > 0)
			cast->hit = 1;
	}
	// printf("mapX : %d, mapY : %d, stepX : %d, stepY : %d, rayX : %f, rayY : %f, player X : %f, player Y : %f\n", 
	// 		cast->mapX, cast->mapY, cast->stepX, cast->stepY, cast->rayDirX, cast->rayDirY, info->player.posX, info->player.posY);
	if (cast->side == 0)
		cast->perpwallDist = (cast->mapX - info->player.posX + (1 - cast->stepX) / 2) / cast->rayDirX;
	else
		cast->perpwallDist = (cast->mapY - info->player.posY + (1 - cast->stepY) / 2) / cast->rayDirY;
}

void		calc_wall_height(t_cast *cast, t_dda *dda, t_config *conf, int x)
{
	int		d_y;
	int		tex_y;
	int		color;
	int		texHeight;

	texHeight = conf->tex[1].texHeight;
	dda->step = 1.0 * texHeight / dda->lineHeight;
	dda->texPos = (dda->drawSt - conf->screenHeight / 2 + dda->lineHeight / 2) * dda->step;
	d_y = dda->drawSt;
	//printf("drawSt: %d, drawEnd : %d, tex H : %d, tex X : %d\n", dda->drawSt, dda->drawEd, texHeight, dda->texX);
	while (d_y < dda->drawEd)
	{
		tex_y = (int)dda->texPos & (texHeight - 1);
		dda->texPos += dda->step;
		// dda->texN을 계산해서 해당 벽이 NSEW중 어느 벽인지 확인후 color를 넣어준다
		color = conf->tex[1].texture[texHeight * tex_y + dda->texX];
		if (cast->side == 1)
			color = (color >> 1) & 8355711;
		conf->screenBuffer[d_y][x] = color;
		d_y++;
	}
}

void		casting_wall(t_info *info, t_config *conf)
{
	int		x;

	x = 0;
	while (x < conf->screenWidth)
	{
		cast_wall_init(info, &info->config, x);
		calc_sideDist(info);
		calc_dda(&info->cast, info);
		dda_init(&info->dda, &info->cast, &info->config, &info->player);
		calc_wall_height(&info->cast, &info->dda, &info->config, x);
		x++;
	}
}





// void		calc_wall_pos(t_cast *cast, t_dda *dda, t_wall *wall)
// {
// 	if (cast->side == 0 && cast->rayDirX > 0)
// 	{
// 		wall->floorXwall = cast->mapX;
// 		wall->floorYwall = cast->mapY + dda->wallX;
// 	}
// 	else if (cast->side == 0 && cast->rayDirX < 0)
// 	{
// 		wall->floorXwall = cast->mapX + 1.0;
// 		wall->floorYwall = cast->mapY + dda->wallX;
// 	}
// 	else if (cast->side == 1 && cast->rayDirY > 0)
// 	{
// 		wall->floorXwall = cast->mapX + dda->wallX;
// 		wall->floorYwall = cast->mapY;
// 	}
// 	else
// 	{
// 		wall->floorXwall = cast->mapX + dda->wallX;
// 		wall->floorYwall = cast->mapY + 1.0;
// 	}
// }

// void		build_wall(int y, int x, t_info *info, t_wall *wall)
// {
// 	double		weight;
// 	double		currentFloorX;
// 	double		currentFloorY;
// 	int			floorTexX;
// 	int			floorTexY;
// 	//int			checkBoardPattern;
// 	//int			floorTexture;

// 	wall->currentDist = screenHeight / (2.0 * y - screenHeight);
// 	weight = (wall->currentDist - wall->distPlayer) / (wall->distWall - wall->distPlayer);
// 	currentFloorX = weight * wall->floorXwall + (1.0 - weight) * info->player.posX;
// 	currentFloorY = weight * wall->floorYwall + (1.0 - weight) * info->player.posY;

// 	floorTexX = (int)(currentFloorX * texWidth) % texWidth;
// 	floorTexY = (int)(currentFloorY * texHeight) % texHeight;

// 	info->config.screenBuffer[y][x] = (info->config.texture[3][texWidth * floorTexY + floorTexX] >> 1) & 835711;
// 	info->config.screenBuffer[screenHeight - y][x] = info->config.texture[6][texWidth * floorTexY + floorTexX];
// }