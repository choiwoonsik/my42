/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_info_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:51:36 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/27 18:21:51 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					all_info_check(t_info *info)
{
	if (!info->config.cl_color || !info->config.fl_color
		|| !info->config.map_height || !info->config.map_width
		|| !info->config.screen_height || !info->config.screen_width)
		return (FALSE);
	return (TRUE);
}
