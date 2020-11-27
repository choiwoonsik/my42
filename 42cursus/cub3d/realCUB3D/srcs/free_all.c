/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:44:16 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/27 18:22:07 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			free_map_tex(t_info *info)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		free(info->config.tex[i].texture);
		info->config.tex[i].texture = NULL;
	}
	i = -1;
	while (++i < info->config.map_height)
	{
		free(info->config.world_map[i]);
		info->config.world_map[i] = NULL;
	}
	info->config.tex = NULL;
}

void			free_screen(t_info *info)
{
	int		y;

	y = -1;
	while (++y < info->config.screen_height)
	{
		free(info->config.screen_buffer[y]);
		info->config.screen_buffer[y] = NULL;
	}
	free(info->config.screen_buffer);
	info->config.screen_buffer = NULL;
}

void			free_img_data(t_info *info)
{
	int		size;
	int		i;

	size = 0;
	i = -1;
	while (info->img.data[size])
		size++;
	while (++i < size - 1)
		info->img.data[size] = '\0';
}

void			f_free(t_info *info)
{
	free_screen(info);
	free_map_tex(info);
	free_img_data(info);
}
