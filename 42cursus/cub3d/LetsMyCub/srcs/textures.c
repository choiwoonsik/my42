/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:37:17 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 13:29:47 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int		y;
	int		x;

	y = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);
	
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
	mlx_destroy_image(info->mlx, img->img);	
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->config.texture[0], "./pics/bluestone.xpm", &img);
	load_image(info, info->config.texture[1], "./pics/pillar.xpm", &img);
	load_image(info, info->config.texture[2], "./pics/eagle.xpm", &img);
	load_image(info, info->config.texture[3], "./pics/greystone.xpm", &img);
	load_image(info, info->config.texture[4], "./pics/greenlight.xpm", &img);
	load_image(info, info->config.texture[5], "./pics/mossy.xpm", &img);
	load_image(info, info->config.texture[6], "./pics/colorstone.xpm", &img);
	load_image(info, info->config.texture[7], "./pics/purplestone.xpm", &img);
}