/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:37:17 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/18 23:36:54 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int				*copy_img_texture(t_img *img, int *texture)
{
	int		y;
	int		x;

	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	return (texture);
}

static int			*load_image(t_info *info, char *path, t_img *img, int idx)
{
	int		*texture;

	for (int i = 0; i < 5; i++)
		printf("all path : %d: %s\n", i, info->config.tex[i].texPath);
	
	if (!(img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height)))
		ERROR_MESSAGE(info, FALSE, "img error");
	printf("img w : %d, img h : %d\n", img->img_width, img->img_height);

	info->config.tex[idx].texWidth = img->img_width;
	info->config.tex[idx].texHeight = img->img_height;
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);
	if (!(texture = (int *)malloc(sizeof(int) * img->img_height * img->img_width)))
		ERROR_MESSAGE(info, FALSE, "alloc error");

	texture = copy_img_texture(img, texture);
	return (texture);
}

int			load_texture(t_info *info)
{
	t_img		img;
	int			i;

	i = -1;
	while (++i < 5)
	{
		if (!(info->config.tex[i].texture = load_image(info, info->config.tex[i].texPath, &img, i)))
			return (FALSE);
		free(info->config.tex[i].texPath);
		info->config.tex[i].texPath = NULL;
	}
	//mlx_destroy_image(info->mlx, img.img);
	return (TRUE);
}