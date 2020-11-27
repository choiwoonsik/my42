/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:16:24 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/27 14:20:52 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			key_w(t_info *info)
{
	if ((info->config.world_map
	[(int)(info->player.pos_x + info->player.dir_x * info->config.move_speed)]
	[(int)info->player.pos_y] - '0') == 0)
		info->player.pos_x += info->player.dir_x * info->config.move_speed;
	if ((info->config.world_map[(int)info->player.pos_x]
	[(int)(info->player.pos_y + info->player.dir_y * info->config.move_speed)]
							- '0') == 0)
		info->player.pos_y += info->player.dir_y * info->config.move_speed;
}

void			key_s(t_info *info)
{
	if ((info->config.world_map
	[(int)(info->player.pos_x - info->player.dir_x * info->config.move_speed)]
	[(int)info->player.pos_y] - '0') == 0)
		info->player.pos_x -= info->player.dir_x * info->config.move_speed;
	if ((info->config.world_map[(int)info->player.pos_x]
	[(int)(info->player.pos_y - info->player.dir_y * info->config.move_speed)]
							- '0') == 0)
		info->player.pos_y -= info->player.dir_y * info->config.move_speed;
}

void			key_d(t_info *info)
{
	double		old_dir_x;
	double		old_cam_x;

	old_dir_x = info->player.dir_x;
	info->player.dir_x = info->player.dir_x * cos(-info->config.rot_speed)
	- info->player.dir_y * sin(-info->config.rot_speed);
	info->player.dir_y = old_dir_x * sin(-info->config.rot_speed)
	+ info->player.dir_y * cos(-info->config.rot_speed);
	old_cam_x = info->player.cam_x;
	info->player.cam_x = info->player.cam_x * cos(-info->config.rot_speed)
	- info->player.cam_y * sin(-info->config.rot_speed);
	info->player.cam_y = old_cam_x * sin(-info->config.rot_speed)
	+ info->player.cam_y * cos(-info->config.rot_speed);
}

void			key_a(t_info *info)
{
	double		old_dir_x;
	double		old_cam_x;

	old_dir_x = info->player.dir_x;
	info->player.dir_x = info->player.dir_x * cos(info->config.rot_speed)
	- info->player.dir_y * sin(info->config.rot_speed);
	info->player.dir_y = old_dir_x * sin(info->config.rot_speed)
	+ info->player.dir_y * cos(info->config.rot_speed);
	old_cam_x = info->player.cam_x;
	info->player.cam_x = info->player.cam_x * cos(info->config.rot_speed)
	- info->player.cam_y * sin(info->config.rot_speed);
	info->player.cam_y = old_cam_x * sin(info->config.rot_speed)
	+ info->player.cam_y * cos(info->config.rot_speed);
}

int				key_control(int key, t_info *info)
{
	if (key == KEY_W)
	{
		key_w(info);
	}
	if (key == KEY_S)
	{
		key_s(info);
	}
	if (key == KEY_D)
	{
		key_d(info);
	}
	if (key == KEY_A)
	{
		key_a(info);
	}
	if (key == KEY_ESCAPE)
	{
		f_free(info);
		exit(0);
	}
	return (0);
}
