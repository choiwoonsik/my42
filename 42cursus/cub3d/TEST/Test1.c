/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:49:34 by wchoi             #+#    #+#             */
/*   Updated: 2020/10/21 11:02:57 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header/cub3d.h"

int main(void)
{
	void	*mlx;
	void	*win;

	//mlx_init()으로 창 생성 - 반환값은 void*
	mlx = mlx_init();
	//mlx의 창 크기로 x500*y500 설정, title로 "mlx_project" - void*, int, int, char*
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	// void* 창을 계속 돌려준다
	mlx_loop(mlx);
}