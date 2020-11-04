/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:06:43 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 15:23:36 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (n < 0)
	{
		un = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		un = n;
	if (un > 9)
		ft_putnbr_fd(un / 10, fd);
	ft_putchar_fd(un % 10 + '0', fd);
}
