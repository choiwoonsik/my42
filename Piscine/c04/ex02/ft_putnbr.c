/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:52:46 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/03 17:52:58 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	div_n(int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		div_n(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			div_n(147483648);
		}
		else
			(div_n(nb * -1));
	}
	else
	{
		div_n(nb);
	}
}
