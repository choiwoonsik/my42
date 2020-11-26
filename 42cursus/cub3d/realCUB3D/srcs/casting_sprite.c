/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:50:05 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 12:21:15 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sort_order(t_pair *pair, int count)
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
			if (pair[j].first > pair[j + 1].first)
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

void		sort_sprite(t_sp *sp)
{
	t_pair	*sprites;
	int		i;

	i = -1;
	sprites = (t_pair *)malloc(sizeof(t_pair) * sp->count);
	while (++i < sp->count)
	{
		sprites[i].first = sp->sp_dis[i];
		sprites[i].second = sp->sp_order[i];
	}
	sort_order(sprites, sp->count);
	i = -1;
	while (++i < sp->count)
	{
		sp->sp_dis[i] = sprites[sp->count - i - 1].first;
		sp->sp_order[i] = sprites[sp->count - i - 1].second;
	}
	free(sprites);
}

void		init_sprite_arr(t_sp *sp, t_info *info)
{
	int		i;

	i = -1;
	while (++i < sp->count)
	{
		sp->sp_order[i] = i;
		sp->sp_dis[i] = (info->player.pos_x - sp->sp_arr[i].x) *
						(info->player.pos_x - sp->sp_arr[i].x)
						+ (info->player.pos_y - sp->sp_arr[i].y) *
						(info->player.pos_y - sp->sp_arr[i].y);
	}
}

void		casting_sprite(t_sp *sp, t_info *info)
{
	init_sprite_arr(sp, info);
	sort_sprite(sp);
}
