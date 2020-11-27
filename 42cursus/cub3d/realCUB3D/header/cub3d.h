/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:29:20 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/27 18:24:47 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define TRUE					1
# define FALSE					0
# define KEY_PRESS				2
# define KEY_RELEASE			3
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13
# define KEY_EXIT				17
# define KEY_ESCAPE				53
# define BUFFER_SIZE			16
# define CUB_EA					0
# define CUB_WE					1
# define CUB_SO					2
# define CUB_NO					3
# define CUB_S					4
# define CUB_FL					5
# define CUB_CL					6
# define CUB_R					7
# define CUB_MAP				10
# define U_DIV					1
# define V_DIV					1
# define V_MOVE					0.0
# define RGB					3
# define FILE_HEADER_SIZE		14
# define IMG_HEADER_SIZE		40
# define SAVE					77

typedef struct	s_floor
{
	float		ray_dirx0;
	float		ray_diry0;
	float		ray_dirx1;
	float		ray_diry1;
	int			p;
	float		pos_z;
	float		row_dist;
	float		fl_step_x;
	float		fl_step_y;
	float		fl_x;
	float		fl_y;
	int			cl_x;
	int			cl_y;
	int			tex_x;
	int			tex_y;
	int			color;
}				t_floor;

typedef struct	s_wall
{
	double		dist_wall;
	double		dist_player;
	double		cur_dist;
	double		fl_x_wall;
	double		fl_y_wall;
}				t_wall;

typedef struct	s_dda
{
	int			line_height;
	int			draw_st;
	int			draw_ed;
	double		wall_x;
	int			tex_n;
	int			tex_x;
	double		tex_pos;
	double		step;
}				t_dda;

typedef struct	s_cast
{
	double		camera_x;
	double		ray_dirx;
	double		ray_diry;
	int			map_x;
	int			map_y;
	double		del_dist_x;
	double		del_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_d;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
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

typedef	struct	s_texture
{
	char		*tex_path;
	int			*texture;
	int			tex_width;
	int			tex_height;
}				t_tex;

typedef struct	s_config
{
	double		move_speed;
	double		rot_speed;
	char		**world_map;
	int			map_height;
	int			map_width;
	int			**screen_buffer;
	int			screen_height;
	int			screen_width;
	t_tex		*tex;
	int			fl_color;
	int			cl_color;
}				t_config;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		cam_x;
	double		cam_y;
}				t_player;

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_sp
{
	t_pos		*sp_arr;
	int			count;
	double		*z_buffer;
	int			*sp_order;
	double		*sp_dis;
	double		sprite_x;
	double		sprite_y;
	int			sprite_height;
	int			sprite_width;
	int			draw_st_x;
	int			draw_st_y;
	int			draw_ed_x;
	int			draw_ed_y;
	double		inv_cam_mtx;
	double		inv_x;
	double		inv_y;
	int			sp_screen_x;
	int			v_move_screen;
}				t_sp;

typedef struct	s_val
{
	int			y;
	int			dis;
	int			sc_h;
	int			sc_w;
	int			tex_x;
	int			tex_y;
	int			color;
	int			tex_w;
	int			tex_h;
}				t_val;

typedef struct	s_bitmapfile
{
	void		*ptr;
	void		*win;
	t_img		screen;
	t_pos		size;
	t_pos		half;
	double		ratio;
}				t_bmp;

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

int				error_message(t_info *info, int exit_code, char *error_message);

int				main_loop(t_info *info);

void			calc(t_info *info, t_sp *sp);

void			draw(t_info *info);

void			mini_value_init(t_info *info);

void			mini_screen_init(t_info *info);

void			mini_init(t_info *info, t_config *conf);

int				mini_config_init(t_info *info);

void			f_free(t_info *info);

int				get_next_line(int fd, char **line);

int				parse_info(t_info *info, char *path);

int				parse_by_type(t_info *info, char *line, int ret, int type);

int				parse_screen_size(t_info *info, char *line);

char			*parse_path(char *line);

int				parse_color(char *line);

char			*update_map(char *buffer, char *line);

int				is_possible_map(t_info *info, t_config *conf);

int				key_control();

int				load_texture(t_info *info);

void			cast_wall_init(t_info *info, t_config *conf, int x);

void			dda_init(t_dda *dda, t_cast *cast, t_config *conf, t_player *p);

void			casting_wall(t_info *info, t_config *conf, t_sp *sp);

void			casting_floor(t_info *info);

int				free_line(char *line, int ret);

int				is_upper(char c);

int				is_space(int c);

int				is_digit(char c);

int				pass_upper_space(char *line, int i);

int				exit_game(void *param);

int				sprite_init(t_info *info, t_sp *sp);

void			casting_sprite(t_sp *sp, t_info *info);

void			calc_sprite(t_sp *sp, t_info *info);

int				screenshot(t_info *info);

void			draw_screen(t_info *info);

int				all_info_check(t_info *info);

#endif
