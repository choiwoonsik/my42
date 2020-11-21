/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:15:16 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/20 17:47:26 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int				g_turned;

void				player_dir_setting(t_info *info, char dir)
{
	int i;

	i = -1;
	if (dir == 'N')
		return ;
	else if (dir == 'E')
	{
		while (++i < 6)
			key_control(KEY_D, info);
	}
	else if (dir == 'S')
	{
		i = -1;
		while (++i < 12)
			key_control(KEY_D, info);
	}
	else if (dir == 'W')
	{
		i = -1;
		while (++ i < 6)
			key_control(KEY_A, info);
	}
}

void		player_pos_setting(t_player *player, t_config *conf ,int x, int y)
{	
	conf->worldMap[x][y] = '0';
	player->posX = (double)x;
	player->posY = (double)y;
}

int				check_4way(t_config *conf, int x, int y)
{
	if (x <= 0 || x >= conf->mapHeight - 1 || y <= 0 || y >= conf->mapWidth - 1)
	{
		return (FALSE);
	}
	else if (conf->worldMap[x][y + 1] == '\0' || conf->worldMap[x][y + 1] == ' ')
	{
		return (FALSE);
	}
	else if (conf->worldMap[x][y - 1] == ' ')
	{
		return (FALSE);
	}
	else if (conf->worldMap[x - 1][y] == ' ' || conf->worldMap[x - 1][y] == '\0')
	{
		return (FALSE);
	}
	else if ((conf->worldMap[x + 1][y] == ' ') || (conf->worldMap[x + 1][y] == '\0'))
		return (FALSE);
	return (TRUE);
}

int				isValid(t_info *info, int x, int y)
{
	if (ft_strchr("NSEW", info->config.worldMap[x][y]) && !g_turned)
	{
		player_dir_setting(info, info->config.worldMap[x][y]);
		player_pos_setting(&info->player, &info->config, x, y);
		g_turned = TRUE;
	}
	else if (info->config.worldMap[x][y] - '0' == 2
			|| info->config.worldMap[x][y] - '0' == 0)
	{
		if (!(check_4way(&info->config, x, y)))
			return (FALSE);
	}
	else if (ft_strchr("1 ", info->config.worldMap[x][y]))
		return (TRUE);
	else
	{
		return (FALSE);
	}
	return (TRUE);
}

int				isPossible_map(t_info *info, t_config *conf)
{
	int				y;
	int				x;

	g_turned = FALSE;
	x = -1;
	while (conf->worldMap[++x])
	{
		y = -1;
		while (conf->worldMap[x][++y])
		{
			if (!(isValid(info, x, y)))
				return (FALSE);
		}
	}
	return (TRUE);
}