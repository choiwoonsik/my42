/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 08:57:44 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/01 09:34:28 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	show(int i, int j, int column, int row)
{
	int		row_last;
	int		col_last;

	row_last = row - 1;
	col_last = column - 1;
	if ((j == 0 && i == 0) || ((j == col_last && i == row_last) && (i != 0 && j != 0)))
		put_char('A');
	else if ((j == 0 && i == row_last) || (j == col_last && i == 0))
		put_char('C');
	else
	{
		if (i == 0 || i == row_last || j == 0 || j == col_last)
			put_char('B');
		else
			put_char(' ');
	}
}

void	rush(int column, int row)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			show(i, j, column, row);
			j++;
		}
		i++;
		put_char('\n');
	}
}

int	main(void)
{
	rush(5, 1);
	rush(1, 5);
	rush(5, 5);
}