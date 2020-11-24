/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:27:24 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/24 17:04:32 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			calcSprite(t_sp *sp, t_info *info, t_player *p, int idx)
{
	t_val		v;

	v.ScH = info->config.screenHeight;
	v.ScW = info->config.screenWidth;
	sp->spriteX = sp->spArr[sp->spOrder[idx]].x - p->posX + 0.5;
	sp->spriteY = sp->spArr[sp->spOrder[idx]].y - p->posY + 0.5;
	sp->invCamMtx = 1.0 / (p->camX * p->dirY - p->dirX * p->camY);
	sp->invX = sp->invCamMtx * (p->dirY * sp->spriteX - p->dirX * sp->spriteY);
	sp->invY = sp->invCamMtx * (-p->camY * sp->spriteX + p->camX * sp->spriteY);
	sp->spScreenX = (int)((v.ScW / 2) * (1 + sp->invX / sp->invY));
	sp->vMoveScreen = (int)(vMove / sp->invY);
	sp->spriteHeight = (int)fabs((v.ScH / sp->invY) / vDiv);
	sp->drawStartY = -sp->spriteHeight / 2 + v.ScH / 2 + sp->vMoveScreen;
	if (sp->drawStartY < 0)
		sp->drawStartY = 0;
	sp->drawEndY = sp->spriteHeight / 2 + v.ScH / 2 + sp->vMoveScreen;
	if (sp->drawEndY >= v.ScH)
		sp->drawEndY = v.ScH - 1;
	sp->spriteWidth = (int)fabs((v.ScH / sp->invY) / uDiv);
	sp->drawStartX = -sp->spriteWidth / 2 + sp->spScreenX;
	if (sp->drawStartX < 0)
		sp->drawStartX = 0;
	sp->drawEndX = sp->spriteWidth / 2 + sp->spScreenX;
	if (sp->drawEndX >= v.ScW)
		sp->drawEndX = v.ScW - 1;
}

void			calcSprite2(t_sp *sp, t_info *info, int stripe)
{
	t_val		v;

	v.ScH = info->config.screenHeight;
	v.ScW = info->config.screenWidth;
	v.texW = info->config.tex[cub_S].texWidth;
	v.texH = info->config.tex[cub_S].texHeight;
	v.texX = (int)((256 * (stripe - (-sp->spriteWidth
				/ 2 + sp->spScreenX)) * v.texW / sp->spriteWidth) / 256);
	if (sp->invY > 0 && stripe > 0 && stripe < v.ScW
		&& sp->invY < sp->zBuffer[stripe])
	{
		v.y = sp->drawStartY;
		while (v.y < sp->drawEndY)
		{
			v.d = (v.y - sp->vMoveScreen) * 256 - v.ScH * 128 + sp->spriteHeight * 128;
			v.texY = ((v.d * v.texH) / sp->spriteHeight) / 256;
			v.color = info->config.tex[cub_S].texture[v.texW * v.texY + v.texX];
			if ((v.color & 0x00FFFFFF) != 0)
				info->config.screenBuffer[v.y][stripe] = v.color;
			v.y++;
		}
	}
}

void			calc_sprite(t_sp *sp, t_info *info)
{
	int 		i;
	int			spripe;

	i = -1;
	while (++i < sp->count)
	{
		calcSprite(sp, info, &info->player, i);
		spripe = sp->drawStartX;
		while (spripe < sp->drawEndX)
		{
			calcSprite2(sp, info, spripe);
			spripe++;
		}
	}
}