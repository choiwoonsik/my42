/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:50:40 by wchoi             #+#    #+#             */
/*   Updated: 2020/05/28 22:14:10 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	show(int n)
{
	int	top;
	int bot;

	if (n > 9)
	{
		top = n / 10;
		bot = n % 10;
		ft_putchar(top + 48);
		ft_putchar(bot + 48);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(n + 48);
	}
}

void	ft_print_comb2(void)
{
	int		first;
	int		second;

	first = 0;
	second = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			show(first);
			ft_putchar(' ');
			show(second);
			if (first < 98 || second < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			second++;
		}
		first++;
	}
}
