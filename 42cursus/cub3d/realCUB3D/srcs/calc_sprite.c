/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:27:24 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 13:01:32 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			sp_info_second(t_sp *sp, t_info *info)
{
	t_val		v;

	v.sc_h = info->config.screen_height;
	v.sc_w = info->config.screen_width;
	sp->draw_st_y = -sp->sprite_height / 2 +
					v.sc_h / 2 + sp->v_move_screen;
	sp->draw_ed_y = sp->sprite_height / 2 +
					v.sc_h / 2 + sp->v_move_screen;
	if (sp->draw_st_y < 0)
		sp->draw_st_y = 0;
	if (sp->draw_ed_y >= v.sc_h)
		sp->draw_ed_y = v.sc_h - 1;
	sp->sprite_width = (int)fabs((v.sc_h / sp->inv_y) / U_DIV);
	sp->draw_st_x = -sp->sprite_width / 2 + sp->sp_screen_x;
	sp->draw_ed_x = sp->sprite_width / 2 + sp->sp_screen_x;
	if (sp->draw_st_x < 0)
		sp->draw_st_x = 0;
	if (sp->draw_ed_x >= v.sc_w)
		sp->draw_ed_x = v.sc_w - 1;
}

void			sp_info(t_sp *sp, t_info *info, t_player *p, int idx)
{
	t_val		v;

	v.sc_h = info->config.screen_height;
	v.sc_w = info->config.screen_width;
	sp->sprite_x = sp->sp_arr[sp->sp_order[idx]].x
					- p->pos_x + 0.5;
	sp->sprite_y = sp->sp_arr[sp->sp_order[idx]].y
					- p->pos_y + 0.5;
	sp->inv_cam_mtx = 1.0 / (p->cam_x * p->dir_y - p->dir_x * p->cam_y);
	sp->inv_x = sp->inv_cam_mtx
				* (p->dir_y * sp->sprite_x - p->dir_x * sp->sprite_y);
	sp->inv_y = sp->inv_cam_mtx
				* (-p->cam_y * sp->sprite_x + p->cam_x * sp->sprite_y);
	sp->sp_screen_x = (int)((v.sc_w / 2) * (1 + sp->inv_x / sp->inv_y));
	sp->v_move_screen = (int)(V_MOVE / sp->inv_y);
	sp->sprite_height = (int)fabs((v.sc_h / sp->inv_y) / V_DIV);
}

void			calc_sprite_second(t_sp *sp, t_info *info, int stripe)
{
	t_val		v;

	v.sc_h = info->config.screen_height;
	v.sc_w = info->config.screen_width;
	v.tex_w = info->config.tex[CUB_S].tex_width;
	v.tex_h = info->config.tex[CUB_S].tex_height;
	v.tex_x = (int)((256 * (stripe - (-sp->sprite_width
				/ 2 + sp->sp_screen_x)) * v.tex_w / sp->sprite_width) / 256);
	if (sp->inv_y > 0 && stripe > 0 && stripe < v.sc_w
		&& sp->inv_y < sp->z_buffer[stripe])
	{
		v.y = sp->draw_st_y;
		while (v.y < sp->draw_ed_y)
		{
			v.dis = (v.y - sp->v_move_screen) * 256 - v.sc_h
					* 128 + sp->sprite_height * 128;
			v.tex_y = ((v.dis * v.tex_h) / sp->sprite_height) / 256;
			v.color = info->config.tex[CUB_S].texture
						[v.tex_w * v.tex_y + v.tex_x];
			if ((v.color & 0x00FFFFFF) != 0)
				info->config.screen_buffer[v.y][stripe] = v.color;
			v.y++;
		}
	}
}

void			calc_sprite(t_sp *sp, t_info *info)
{
	int			i;
	int			spripe;

	i = -1;
	while (++i < sp->count)
	{
		sp_info(sp, info, &info->player, i);
		sp_info_second(sp, info);
		spripe = sp->draw_st_x;
		while (spripe < sp->draw_ed_x)
		{
			calc_sprite_second(sp, info, spripe);
			spripe++;
		}
	}
}
