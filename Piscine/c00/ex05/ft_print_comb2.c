/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:30:38 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/04 10:52:21 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '9')
	{
		j = i + 1;
		while (j <= '9')
		{
			k = j + 1;
			while (k <= '9')
			{
				if (i != '0' || j != '1' || k != '2')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				ft_putchar(i);
				ft_putchar(j);
				ft_putchar(k);
				k++;
			}
			j++;
		}
		i++;
	}
}

int		main(void)
{
	ft_print_comb();
}
