/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:19:23 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/19 11:59:58 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			mini_value_init(t_info *info)
{
	info->player.posX = 6.0;
	info->player.posY = 2.0;
	info->player.dirX = -1.0;
	info->player.dirY = 0.0;
	info->player.camX = 0.0;
	info->player.camY = 0.66;
	info->config.moveSpeed = 0.2;
	info->config.rotSpeed = 0.2;
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

int				mini_screen_init(t_info *info)
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
	return (0);
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

int				mini_init(t_info *info, t_config *conf)
{
	info->mlx = mlx_init();

	info->win = mlx_new_window(info->mlx, conf->screenWidth, conf->screenHeight, "cub3d");
	info->img.img = mlx_new_image(info->mlx, conf->screenWidth, conf->screenHeight);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
	&info->img.bits_per_pixel, &info->img.size_line, &info->img.endian);

	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, KEY_PRESS, 0, &key_control, info);
	mlx_hook(info->win, KEY_EXIT, 0, &exit_game, info);
	mlx_loop(info->mlx);
	return (0);
}