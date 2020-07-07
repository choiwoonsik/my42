/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:34:27 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/11 09:38:42 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char *base, unsigned int n, unsigned int len)
{
	char	c;

	if (n >= len)
		c = base[n % len];
	else
		c = base[n];
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}

int		check_base(char *base)
{
	int		i;
	int		j;
	int		base_len;
	int		tmp;

	base_len = ft_strlen(base);
	if (base_len == 1 || base_len == 0)
		return (0);
	i = 0;
	while (i < base_len - 1)
	{
		tmp = base[i];
		j = i + 1;
		while (j < base_len)
		{
			if (tmp == base[j] || base[j] == '+' || base[j] == '-'
			|| base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	div_n(unsigned int nbr, unsigned int len, char *base)
{
	if (nbr < len)
	{
		print_char(base, nbr, len);
	}
	else if (nbr >= len)
	{
		div_n(nbr / len, len, base);
		print_char(base, nbr, len);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char				c;
	unsigned	int		len;
	unsigned	int		u_nbr;

	len = ft_strlen(base);
	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		c = '-';
		write(1, &c, 1);
		u_nbr = -nbr;
	}
	else
		u_nbr = nbr;
	div_n(u_nbr, len, base);
}
