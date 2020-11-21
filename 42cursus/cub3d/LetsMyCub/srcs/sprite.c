/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:51:56 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/20 20:56:43 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			count_sprite(t_config *conf, t_sp_info *sp)
{
	int		i;
	int		j;

	sp->sp_count = 0;
	i = -1;
	while (conf->worldMap[++i])
	{
		j = -1;
		while (conf->worldMap[i][++j])
		{
			if (conf->worldMap[i][j] == '2')
				sp->sp_count++;
		}
	}
	printf("count > %d\n", sp->sp_count);
}

int				init_sprite(t_info *info, t_sp_info *sp)
{
	int		width;
	
	count_sprite(&info->config, sp);
	width = info->config.screenWidth;
	if (!(sp->zBuffer = (double *)malloc(sizeof (double) * width + 1)))
		return (FALSE);
	sp->zBuffer[width] = '\0';
	if(!(sp->sp_OrderArr = (int *)malloc(sizeof (int) * sp->sp_count + 1)))
		return (FALSE);
	sp->sp_OrderArr[sp->sp_count] = '\0';
	if(!(sp->sp_DistArr = (double *)malloc(sizeof (double) * sp->sp_count + 1)))
		return (FALSE);
	sp->sp_DistArr[sp->sp_count] = '\0';
	return (TRUE);
}