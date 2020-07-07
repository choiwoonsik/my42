/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:52:22 by wchoi             #+#    #+#             */
/*   Updated: 2020/05/29 10:20:00 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_last(char buff[], int n)
{
	int pos;
	int num;

	pos = n - 1;
	num = 9;
	while (pos >= 0)
	{
		if (buff[pos] != num + '0')
			return (0);
		--pos;
		--num;
	}
	return (1);
}

void	solve_re(int pos, char buff[], int n)
{
	char cur;

	if (pos == n)
	{
		write(1, buff, n);
		if (is_last(buff, n) == 0)
			write(1, ", ", 2);
		return ;
	}
	if (pos == 0)
		cur = '0';
	else
	{
		cur = buff[pos - 1] + 1;
	}
	while (cur <= '9')
	{
		buff[pos] = cur;
		solve_re(pos + 1, buff, n);
		++cur;
	}
}

void	ft_print_combn(int n)
{
	int		pos;
	char	buff[10];

	pos = 0;
	solve_re(pos, buff, n);
}
