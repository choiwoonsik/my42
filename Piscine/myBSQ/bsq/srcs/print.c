/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skweon <skweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:12:51 by skweon            #+#    #+#             */
/*   Updated: 2020/06/18 02:35:41 by skweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "all.h"

void	mark_largest_square(t_info *info, t_max *ans)
{
	int row;
	int col;

	row = 0;
	while (row < ans->size)
	{
		col = 0;
		while (col < ans->size)
		{
			(info->map)[ans->row - row][ans->col - col] = info->mark;
			col++;
		}
		row++;
	}
}

void	print_max(t_info *info)
{
	int row;
	int col;

	row = 0;
	while (row < info->line_num)
	{
		col = 0;
		while ((info->map)[row][col] != '\0')
		{
			write(1, &((info->map)[row][col]), 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
