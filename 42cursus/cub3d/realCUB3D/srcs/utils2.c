/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:13:04 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 11:32:40 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				pass_upper_space(char *line, int i)
{
	while (is_upper(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	return (i);
}

int				exit_game(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	f_free(info);
	exit(0);
	return (0);
}
