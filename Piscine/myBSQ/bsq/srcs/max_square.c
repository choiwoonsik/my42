/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skweon <skweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:17:18 by skweon            #+#    #+#             */
/*   Updated: 2020/06/18 03:30:51 by skweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "all.h"

void			free_note(int **note, int line_num)
{
	int i;

	i = 0;
	while (i < line_num)
	{
		free(note[i]);
		i++;
	}
	free(note);
}

int				**prepare_note(t_info *info, int len)
{
	int row;
	int	**note;

	note = (int **)malloc(sizeof(int*) * info->line_num);
	if (note == 0)
		return (0);
	row = 0;
	while (row < info->line_num)
	{
		note[row] = (int *)malloc(sizeof(int) * len);
		if (note[row] == 0)
		{
			free_note(note, row);
			return (0);
		}
		row++;
	}
	return (note);
}

int				get_value(int **note, t_info *info, int r, int c)
{
	int		val;
	int		tmp;

	if (r == 0 || c == 0)
		val = (info->map[r][c] == info->obs) ? 0 : 1;
	else
	{
		if ((info->map)[r][c] == info->obs)
			val = 0;
		else
		{
			tmp = (note[r][c - 1] < note[r - 1][c]) ?
				note[r][c - 1] : note[r - 1][c];
			val = (note[r - 1][c - 1] < tmp) ? note[r - 1][c - 1] + 1 : tmp + 1;
		}
	}
	return (val);
}

t_max			*find_answer_point(int **note, t_info *info, int len)
{
	int			col;
	int			row;
	t_max		*ans;

	if ((ans = (t_max *)malloc(sizeof(t_max))) == 0)
		return (0);
	ans->size = 0;
	ans->col = 0;
	ans->row = 0;
	row = 0;
	while (row < info->line_num)
	{
		col = 0;
		while (col < len)
		{
			note[row][col] = get_value(note, info, row, col);
			ans->row = note[row][col] > ans->size ? row : ans->row;
			ans->col = note[row][col] > ans->size ? col : ans->col;
			ans->size = note[row][col] > ans->size ? note[row][col] : ans->size;
			col++;
		}
		row++;
	}
	return (ans);
}

t_max			*find_largest_square(t_info *info)
{
	int			len;
	int			**note;
	t_max		*ans;

	if (info == 0)
		return (0);
	len = ft_strlen((info->map)[0]);
	note = prepare_note(info, len);
	if (note == 0)
		return (0);
	ans = find_answer_point(note, info, len);
	free_note(note, info->line_num);
	return (ans);
}
