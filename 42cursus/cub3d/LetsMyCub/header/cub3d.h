/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:29:20 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 18:53:07 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "key_macro.h"
# include "libft.h"
# include "mlx.h"

//map정보 파싱받아서 넣기
#define mapWidth 		24
#define mapHeight 		24
#define screenWidth 	640
#define screenHeight	480
#define texWidth		64
#define texHeight		64
//

typedef struct s_floor
{
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;

	int		p;
	float	posZ;
	float	rowDist;

	float	floorStepX;
	float	floorStepY;
	float	floorX;
	float	floorY;

	int		ceilX;
	int		ceilY;

	int		textureX;
	int		textureY;
	int		color;
}				t_floor;

typedef struct s_wall
{
	double	distWall;
	double	distPlayer;
	double	currentDist;
	double	floorXwall;
	double	floorYwall;
}				t_wall;

typedef struct s_DDA
{
	int		lineHeight;
	int		drawSt;
	int		drawEd;

	double	wallX;
	int		texN;
	int		texX;
	double	texPos;

	double	step;
}				t_dda;

typedef struct	s_cast
{
	double cameraX;
	double rayDirX;
	double rayDirY;

	int mapX;
	int mapY;

	double deltaDistX;
	double deltaDistY;

	double sideDistX;
	double sideDistY;

	double perpwallDist;

	int		stepX;
	int		stepY;

	int		hit;
	int		side;
}				t_cast;

typedef struct	s_img
{
	void		*img;
	int			*data;

	int			bits_per_pixel;
	int			size_line;
	int			endian;

	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_config
{
	// moveSpeed & rotateSpeed
	double		moveSpeed;
	double		rotSpeed;

	int			worldMap[24][24];
	
	int			screenBuffer[screenHeight][screenWidth];
	int			**texture;
	char		*texPath;
}				t_config;

typedef struct s_player
{
	//start pos
	double		posX;
	double		posY;

	//direction vector
	double		dirX;
	double		dirY;

	//camera plane
	double		camX;
	double		camY;
}				t_player;

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_config	config;
	t_player	player;
	t_cast		cast;
	t_dda		dda;
}				t_info;

// 함수 선언

//cub3d.c
int				main_loop(t_info *info);

// init.c
int				mini_init(t_info *info);
void			f_free(t_info *info);

// parsing_info.c
int				parse_info(t_info *info, char *path);

// keyControl.c
int				key_control();

// keyControl2.c
int				exit_game(void *param);

// map.c
void			map_init(t_info *info);

// textures.c
void			load_texture(t_info *info);

// casting_init.c
void			cast_wall_init(t_info *info, int x);
void			dda_init(t_dda *dda, t_cast *cast, t_config *conf, t_player *p);

// casting_wall.c
void			casting_wall(t_info *info);

// casting_wall2.c
// void			calc_wall_pos(t_cast *cast, t_dda *dda, t_wall *wall);
// void			build_wall(int y, int x, t_info *info, t_wall *wall);

// casting_floor.c
void			casting_floor(t_info *info);

#endif