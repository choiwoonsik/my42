/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:39:50 by wchoi             #+#    #+#             */
/*   Updated: 2020/10/21 16:42:37 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

# define TILE_SIZE 32
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

typedef struct s_img
{
	void		*img_ptr;
	int			*data;

	int			width;
	int			height;

	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;

	int			map[ROWS][COLS];
}				t_game;

void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double deltaX;
	double deltaY;
	double step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	draw_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
}



int		main(void)
{
	t_game *game;

	game->mlx_ptr = mlx_init();


	mlx_loop(game->mlx_ptr);
	return(0);
}