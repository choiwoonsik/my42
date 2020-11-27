/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:37:17 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/27 13:24:10 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					*copy_image(t_info *info, t_img *img, int *tex)
{
	int			y;
	int			x;

	if (!(tex = (int *)malloc(sizeof(int)
						* (img->img_height * img->img_width) + 1)))
		error_message(info, FALSE, "alloc error");
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			tex[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	--y;
	--x;
	tex[img->img_width * y + x] = '\0';
	return (tex);
}

static int			*load_image(t_info *info, char *path, t_img *img, int idx)
{
	int			*texture;

	texture = NULL;
	if (!(img->img = mlx_xpm_file_to_image(info->mlx,
					path, &img->img_width, &img->img_height)))
		error_message(info, FALSE, "img error");
	info->config.tex[idx].tex_width = img->img_width;
	info->config.tex[idx].tex_height = img->img_height;
	img->data = (int *)mlx_get_data_addr(img->img,
				&img->bits_per_pixel, &img->size_line, &img->endian);
	texture = copy_image(info, img, texture);
	return (texture);
}

int					load_texture(t_info *info)
{
	t_img		img;
	int			i;

	i = -1;
	while (++i < 5)
	{
		if (!(info->config.tex[i].texture =
		load_image(info, info->config.tex[i].tex_path, &img, i)))
			return (FALSE);
		free(info->config.tex[i].tex_path);
		info->config.tex[i].tex_path = NULL;
	}
	return (TRUE);
}
