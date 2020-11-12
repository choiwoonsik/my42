/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:19:23 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 18:26:00 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			mini_value_init(t_info *info)
{
	info->player.posX = 22.0;
	info->player.posY = 11.5;
	info->player.dirX = -1.0;
	info->player.dirY = 0.0;
	info->player.camX = 0.0;
	info->player.camY = 0.66;
	info->config.moveSpeed = 0.07;
	info->config.rotSpeed = 0.07;
}

int				mini_screen_init(t_info *info)
{
	int i;
	int j;

	if(!(info->config.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	i = -1;
	while (++i < 8)
	{
		if(!(info->config.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
		j = -1;
		while (++j < texHeight * texWidth)
			info->config.texture[i][j] = 0;
	}
	i = -1;
	while (++i < screenHeight)
	{
		j = -1;
		while (++j < screenWidth)
			info->config.screenBuffer[i][j] = 0;
	}
	return (0);
}

void			f_free(t_info *info)
{
	int i = 0;

	while (i < 8)
	{
		free(info->config.texture[i]);
		info->config.texture[i] = NULL;
		i++;
	}
	free(info->config.texture);
	info->config.texture = NULL;
}

int			mini_init(t_info *info)
{
	info->mlx = mlx_init();
	load_texture(info);

	info->win = mlx_new_window(info->mlx, screenWidth, screenHeight, "cub3d");
	info->img.img = mlx_new_image(info->mlx, screenWidth, screenHeight);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
	&info->img.bits_per_pixel, &info->img.size_line, &info->img.endian);

	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, KEY_PRESS, 0, &key_control, info);
	mlx_hook(info->win, KEY_EXIT, 0, &exit_game, info);
	mlx_loop(info->mlx);
	return (0);
}