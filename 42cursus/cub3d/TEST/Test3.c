/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:55:09 by wchoi             #+#    #+#             */
/*   Updated: 2020/10/21 13:39:33 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

/*
이미지 불러와서 창에 출력하기
*/

int main()
{
	void		*mlx;
	void		*win;
	void		*img;

	int			img_width;
	int			img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "load_img");
	img = mlx_xpm_file_to_image(mlx, "./textures/IU_0.xpm", &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, img, img_width, img_height);

	mlx_loop(mlx);
	return (0);
}