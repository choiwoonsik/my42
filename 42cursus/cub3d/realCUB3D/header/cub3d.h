/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:29:20 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/20 21:45:04 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "key_macro.h"
# include "libft.h"
# include "mlx.h"


//map정보 파싱받아서 넣기
#define BUFFER_SIZE		16

#define cub_R			7
#define cub_EA			0
#define cub_WE			1
#define cub_SO			2
#define cub_NO			3
#define cub_S			4
#define cub_FL			5
#define cub_CL			6
#define cub_MAP			10
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

typedef	struct s_texture
{
	char		*texPath;
	int			*texture;
	int			texWidth;
	int			texHeight;
}				t_tex;

typedef struct s_config
{
	// moveSpeed & rotateSpeed
	double		moveSpeed;
	double		rotSpeed;

	char		**worldMap;
	int			mapHeight;
	int			mapWidth;
	
	int			**screenBuffer;
	int			screenHeight;
	int			screenWidth;
	t_tex		*tex;
	int			fl_color;
	int			cl_color;
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

// main.c
int				ERROR_MESSAGE(t_info *info, int exit_code, char *error_message);

//cub3d.c
int				main_loop(t_info *info);

// init.c
void			mini_value_init(t_info *info);
int				mini_screen_init(t_info *info);
int				mini_init(t_info *info, t_config *conf);
int				mini_config_init(t_info *info);
void			f_free(t_info *info);

// gnl.c
int				get_next_line(int fd, char **line);

// parsing_info.c
int				parse_info(t_info *info, char *path);

// parsing_info2.c
int				parse_by_type(t_info *info, char *line, int ret, int type);

// parsing_info3.c
int				parse_screen_size(t_info *info, char *line);
char			*parse_path(char *line);
int				parse_color(char *line);
char			*update_map(char *buffer, char *line);

// map_check.c
int				isPossible_map(t_info *info, t_config *conf);

// keyControl.c
int				key_control();

// keyControl2.c
int				exit_game(void *param);

// textures.c
int				load_texture(t_info *info);

// casting_init.c
void			cast_wall_init(t_info *info, t_config *conf, int x);
void			dda_init(t_dda *dda, t_cast *cast, t_config *conf, t_player *p);

// casting_wall.c
void			casting_wall(t_info *info, t_config *conf);

// casting_floor.c
void			casting_floor(t_info *info);

// utils.c
int				free_line(char *line, int ret);
int				is_upper(char c);
int				is_space(int c);
int				is_digit(char c);

// utils2.c
int				pass_upper_space(char *line, int i);

#endif