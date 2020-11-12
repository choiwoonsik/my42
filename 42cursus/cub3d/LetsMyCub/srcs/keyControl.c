/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyControl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:16:24 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 14:25:02 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			key_w(t_info *info)
{
	if (!info->config.worldMap
	[(int)(info->player.posX + info->player.dirX * info->config.moveSpeed)]
	[(int)info->player.posY])
		info->player.posX += info->player.dirX * info->config.moveSpeed;

	if (!info->config.worldMap
	[(int)info->player.posX]
	[(int)(info->player.posY + info->player.dirY * info->config.moveSpeed)])
		info->player.posY += info->player.dirY * info->config.moveSpeed;
}

void			key_s(t_info *info)
{
	if (!info->config.worldMap
	[(int)(info->player.posX - info->player.dirX * info->config.moveSpeed)]
	[(int)info->player.posY])
		info->player.posX -= info->player.dirX * info->config.moveSpeed;

	if (!info->config.worldMap
	[(int)info->player.posX]
	[(int)(info->player.posY - info->player.dirY * info->config.moveSpeed)])
		info->player.posY -= info->player.dirY * info->config.moveSpeed;
}

void			key_d(t_info *info)
{
	double oldDirX = info->player.dirX;
	info->player.dirX = info->player.dirX * cos(-info->config.rotSpeed)
	- info->player.dirY * sin(-info->config.rotSpeed);

	info->player.dirY = oldDirX * sin(-info->config.rotSpeed)
	+ info->player.dirY * cos(-info->config.rotSpeed);

	double oldCamX = info->player.camX;
	info->player.camX = info->player.camX * cos(-info->config.rotSpeed)
	- info->player.camY * sin(-info->config.rotSpeed);

	info->player.camY = oldCamX * sin(-info->config.rotSpeed)
	+ info->player.camY * cos(-info->config.rotSpeed);
}
void			key_a(t_info *info)
{
	double oldDirX = info->player.dirX;
	info->player.dirX = info->player.dirX * cos(info->config.rotSpeed)
	- info->player.dirY * sin(info->config.rotSpeed);

	info->player.dirY = oldDirX * sin(info->config.rotSpeed)
	+ info->player.dirY * cos(info->config.rotSpeed);

	double oldCamX = info->player.camX;
	info->player.camX = info->player.camX * cos(info->config.rotSpeed)
	- info->player.camY * sin(info->config.rotSpeed);
	
	info->player.camY = oldCamX * sin(info->config.rotSpeed)
	+ info->player.camY * cos(info->config.rotSpeed);
}

int				key_control(int key, t_info *info)
{
	if (key == KEY_W)
	{
		key_w(info);
	}
	if (key == KEY_S)
	{
		key_s(info);
	}
	if (key == KEY_D)
	{
		key_d(info);
	}
	if (key == KEY_A)
	{
		key_a(info);
	}
	if (key == KEY_ESCAPE)
		exit(0);
	return (0);
}