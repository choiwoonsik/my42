/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:41:12 by wchoi             #+#    #+#             */
/*   Updated: 2020/10/21 15:26:34 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 400
# define IMG_HEIGHT 300

#include "header/cub3d.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	//아래 3개 값은 이해 안해도 사용하는데 지장이 없음. 
	//선언한뒤 함수의 인자로만 잘 넣어주면 알아서 정보를 받아나옴.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;


int main(void)
{
	t_mlx		*t_mlx;
	t_img		t_img;
	int			count_w;
	int			count_h;

	t_mlx->mlx_ptr = mlx_init();
	t_mlx->win_ptr = mlx_new_window(t_mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test4");
	t_img.img_ptr = mlx_new_image(t_mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	t_img.data = (int *)mlx_get_data_addr(t_img.img_ptr, &t_img.bpp, &t_img.size_l, &t_img.endian);

	count_h = -1;
	while(++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_w % 2)
				t_img.data[count_h * IMG_WIDTH + count_w] = 0xffffff;
			else
				t_img.data[count_h * IMG_WIDTH + count_w] = 0xff0000;
		}
	}
	mlx_put_image_to_window(t_mlx->mlx_ptr, t_mlx->win_ptr, t_img.img_ptr, 0, 0);
	mlx_loop(t_mlx->mlx_ptr);

	return (0);
}