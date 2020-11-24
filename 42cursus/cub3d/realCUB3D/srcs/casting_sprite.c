/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:50:05 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/24 11:16:56 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sortOrder(t_pair *pair, int count)
{
	t_pair		tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count - 1)
		{
			if (pair[j].first > pair[j+1].first)
			{
				tmp.first = pair[j].first;
				tmp.second = pair[j].second;
				pair[j].first = pair[j + 1].first;
				pair[j].second = pair[j + 1].second;
				pair[j + 1].first = tmp.first;
				pair[j + 1].second = tmp.second;
			}
		}
	}
}

void		sortSprite(t_sp *sp)
{
	t_pair	*sprites;
	int		i;

	i = -1;
	sprites = (t_pair *)malloc(sizeof(t_pair) * sp->count);
	while (++i < sp->count)
	{
		sprites[i].first = sp->spDis[i];
		sprites[i].second = sp->spOrder[i];
	}
	sortOrder(sprites, sp->count);
	i = -1;
	while (++i < sp->count)
	{
		sp->spDis[i] = sprites[sp->count - i - 1].first;
		sp->spOrder[i] = sprites[sp->count - i - 1].second;
	}
	free(sprites);
}

void		init_spriteArr(t_sp *sp, t_info *info)
{
	int		i;

	i = -1;
	while (++i < sp->count)
	{
		sp->spOrder[i] = i;
		sp->spDis[i] = (info->player.posX - sp->spArr[i].x) * (info->player.posX - sp->spArr[i].x)
						+ (info->player.posY  - sp->spArr[i].y) * (info->player.posY - sp->spArr[i].y);
	}
}

void		casting_sprite(t_sp *sp, t_info *info)
{
	init_spriteArr(sp, info);
	sortSprite(sp);
}