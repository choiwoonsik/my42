/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:49:55 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/27 18:24:36 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_int_to_char(unsigned char *bf_size, int size)
{
	bf_size[0] = (unsigned char)(size);
	bf_size[1] = (unsigned char)(size >> 8);
	bf_size[2] = (unsigned char)(size >> 16);
	bf_size[3] = (unsigned char)(size >> 24);
}

static int		write_bmp_header(int file, int file_size, t_info *info)
{
	int				i;
	unsigned char	bmp_header[54];

	i = -1;
	while (++i < 54)
		bmp_header[i] = (unsigned char)(0);
	bmp_header[0] = (unsigned char)('B');
	bmp_header[1] = (unsigned char)('M');
	set_int_to_char(bmp_header + 2, file_size);
	bmp_header[10] = (unsigned char)(FILE_HEADER_SIZE + IMG_HEADER_SIZE);
	bmp_header[14] = (unsigned char)(IMG_HEADER_SIZE);
	set_int_to_char(bmp_header + 18, info->config.screen_width);
	set_int_to_char(bmp_header + 22, info->config.screen_height);
	bmp_header[26] = (unsigned char)(1);
	bmp_header[28] = (unsigned char)(24);
	return (!(write(file, bmp_header, 54) < 0));
}

static int		get_color(t_info *info, int x, int y)
{
	int						rgb;
	int						color;

	color = info->img.data[info->config.screen_width * y + x];
	rgb = ((color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF));
	return (rgb);
}

static int		write_bmp_data(int file, int pad, t_info *info)
{
	unsigned char			zero[RGB];
	int						y;
	int						x;
	int						color;

	x = -1;
	while (++x < 3)
		zero[x] = 0;
	y = info->config.screen_height;
	while (--y > 0)
	{
		x = -1;
		while (++x < info->config.screen_width)
		{
			color = get_color(info, x, y);
			if (write(file, &color, RGB) < 0)
				return (FALSE);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (FALSE);
		}
	}
	return (TRUE);
}

int				screenshot(t_info *info)
{
	int		file;
	int		pad;
	int		file_size;
	int		pxl_of_row;

	draw_screen(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	pxl_of_row = info->config.screen_width * RGB;
	pad = (4 - pxl_of_row % 4) % 4;
	file_size = (FILE_HEADER_SIZE + IMG_HEADER_SIZE)
				+ (RGB * (info->config.screen_width + pad)
				* info->config.screen_height);
	if ((file = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
		return (error_message(info, FALSE, "error file open"));
	if (!write_bmp_header(file, file_size, info))
		return (error_message(info, FALSE, "error bmp header"));
	if (!(write_bmp_data(file, pad, info)))
		return (error_message(info, FALSE, "error bmp data"));
	close(file);
	f_free(info);
	exit(TRUE);
	return (TRUE);
}
