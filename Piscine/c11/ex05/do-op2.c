/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:04:47 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/16 19:16:36 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putnbr(int num)
{
	if (num == -1)
		return (0);
	
	if (num < 0)
	{
		ft_putchar('-');
		if (num == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
		}
		else
			ft_putnbr(num * -1);
	}
	else
	{
		if (num < 10)
		{
			ft_putchar(num + '0');
		}
		else
		{
			ft_putnbr(num / 10);
			ft_putchar(num % 10 + '0');
		}
	}
	return (0);
}