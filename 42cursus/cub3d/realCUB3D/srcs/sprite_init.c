/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:39:04 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/24 16:50:26 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			count_sprite(t_config *conf, t_sp *sp)
{
	int		x;
	int		y;

	x = -1;
	while (++x < conf->mapHeight)
	{
		y = -1;
		while (conf->worldMap[x][++y])
		{
			if (conf->worldMap[x][y] == '2')
			{
				sp->spArr[sp->count].x = x;
				sp->spArr[sp->count].y = y;
				sp->count++;
				//printf("x : %d, y : %d\n", x, y);
			}
		}
	}
}

int				sprite_init(t_info *info, t_sp *sp)
{
	sp->count = 0;
	if (!(sp->spArr = (t_spInfo *)malloc(sizeof(t_spInfo)
			* (info->config.mapHeight * info->config.mapWidth))))
		return (ERROR_MESSAGE(info, FALSE, "error alloc"));
	count_sprite(&info->config, sp);
	if (!(sp->zBuffer = (double *)malloc(sizeof(double) * (info->config.screenWidth + 1))))
		return (ERROR_MESSAGE(info, FALSE, "error alloc"));
	sp->zBuffer[info->config.screenWidth] = '\0';
	if (!(sp->spOrder = (int *)malloc(sizeof(int) * sp->count)))
		return (ERROR_MESSAGE(info, FALSE, "error alloc"));
	if (!(sp->spDis = (double *)malloc(sizeof(double) * sp->count)))
		return (ERROR_MESSAGE(info, FALSE, "error alloc"));
	return (TRUE);
}