/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:59:46 by wchoi             #+#    #+#             */
/*   Updated: 2020/10/21 12:54:28 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

typedef struct s_param
{
	int		x;
	int		y;
	char	str[3];
}				t_param;

void param_init(t_param *param)
{
	param->x = 5;
	param->y = 5;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int	key_press(int keyCode, t_param *param)
{
	static int a = 0;

	if (keyCode == KEY_W)
		param->x++;
	else if (keyCode == KEY_S)
		param->x--;
	else if (keyCode == KEY_ESCAPE)
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int main(void)
{
	
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	printf("start x: %d\n", param.x);
	mlx_hook(win, KEY_PRESS, 0, &key_press, &param);

	mlx_loop(mlx);
}