/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:53:37 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/05 20:53:21 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 400

#define IMG_WIDTH 400
#define IMG_HEIGHT 400

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}				t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;

	int		img_width;
	int		img_height;

	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img;

int main(void)
{
	t_mlx		*mlx;
	t_img		img;

	int			count_w;
	int			count_h;

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test5");
	img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./textures/IU_0.xpm", &img.img_width, &img.img_height);
	img.addr = (int *)mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	
	count_h = -1;
	while (++count_h < img.img_height)
	{
		count_w = -1;
		while (++count_w < img.img_width / 2)
		{
			if (count_w % 2)
				img.addr[count_h * img.img_width + count_w] = 0xffffff;
			else
				img.addr[count_h * img.img_width + count_w] = 0xff0000;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 50, 50);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}



