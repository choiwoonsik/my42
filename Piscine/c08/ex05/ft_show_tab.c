/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 18:05:22 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/10 22:55:54 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

void	ft_putstr(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
	{
		write(1, &str[n], 1);
		n++;
	}
}

void	ft_putnbr(int nbr)
{
	unsigned int	unbr;
	char			num;

	if (nbr < 0)
	{
		num = '-';
		write(1, &num, 1);
		unbr = nbr * -1;
	}
	else
		unbr = nbr;
	if (unbr < 10)
	{
		num = unbr + '0';
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr(unbr / 10);
		num = unbr % 10 + '0';
		write(1, &num, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int idx;

	idx = 0;
	while (par[idx].str != '\0')
	{
		ft_putstr(par[idx].str);
		write(1, "\n", 1);
		ft_putnbr(par[idx].size);
		write(1, "\n", 1);
		ft_putstr(par[idx].copy);
		write(1, "\n", 1);
		idx++;
	}
}
