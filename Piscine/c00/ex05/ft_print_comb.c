/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 13:24:02 by wchoi             #+#    #+#             */
/*   Updated: 2020/05/29 11:52:09 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0' - 1;
	while (++first <= '9')
	{
		second = first;
		while (++second <= '9')
		{
			third = second;
			while (++third <= '9')
			{
				if (first != '0' || second != '1' || third != '2')
					ft_putchar(',');
				if (first != '0' || second != '1' || third != '2')
					ft_putchar(' ');
				ft_putchar(first);
				ft_putchar(second);
				ft_putchar(third);
			}
		}
	}
}
