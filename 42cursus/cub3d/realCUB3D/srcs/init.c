/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:19:23 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/23 23:43:19 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			mini_value_init(t_info *info)
{
	info->player.posX = 3.0;
	info->player.posY = 3.0;
	info->player.dirX = -1.0;
	info->player.dirY = 0.0;
	info->player.camX = 0.0;
	info->player.camY = 0.66;
	info->config.moveSpeed = M_PI_4 / 3;
	info->config.rotSpeed = M_PI_4 / 3;
}

int				mini_config_init(t_info *info)
{
	int		i;

	i = -1;
	info->config.cl_color = 0;
	info->config.fl_color = 0;
	info->config.mapHeight = 0;
	info->config.mapWidth = 0;
	info->config.screenHeight = 0;
	info->config.screenWidth = 0;
	info->config.worldMap = NULL;
	while (++i < 8)
	{
		info->config.tex = (t_tex *)malloc(sizeof(t_tex) * 8);
		info->config.tex[i].texPath = NULL;
		info->config.tex[i].texture = NULL;
		info->config.tex[i].texHeight = 0;
		info->config.tex[i].texWidth = 0;
	}
	return (TRUE);
}

void			mini_screen_init(t_info *info)
{
	int i;
	int j;

	info->config.screenBuffer = (int **)malloc(sizeof(int *) * info->config.screenHeight);
	i = -1;
	while (++i < info->config.screenHeight)
		info->config.screenBuffer[i] = (int *)malloc(sizeof(int) * info->config.screenWidth);	

	i = -1;
	while (++i < info->config.screenHeight)
	{
		j = -1;
		while (++j < info->config.screenWidth)
			info->config.screenBuffer[i][j] = 0;
	}
}

void			mini_init(t_info *info, t_config *conf)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, conf->screenWidth, conf->screenHeight, "cub3d");
	info->img.img = mlx_new_image(info->mlx, conf->screenWidth, conf->screenHeight);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
	&info->img.bits_per_pixel, &info->img.size_line, &info->img.endian);
}

void			f_free(t_info *info)
{
	int i = 0;
	while (i < info->config.mapHeight)
	{
		if (info->config.worldMap[i])
			free(info->config.worldMap[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (info->config.tex[i].texture)
		{
			free(info->config.tex[i].texture);
			info->config.tex[i].texture = NULL;
		}
		i++;
	}
	free(info->config.tex);
}