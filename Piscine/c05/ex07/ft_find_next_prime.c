/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:37:12 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/08 10:04:23 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_prime(int nb)
{
	long long int	i;
	long long int	l_nb;

	i = 2;
	l_nb = nb;
	while (i * i <= l_nb)
	{
		if (l_nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int	j;

	j = 0;
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb + j))
	{
		j++;
	}
	return (nb + j);
}
