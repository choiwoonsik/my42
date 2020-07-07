/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 23:24:54 by wchoi             #+#    #+#             */
/*   Updated: 2020/05/30 10:58:12 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		n;
	int		tmp;

	n = 0;
	while (n < size / 2)
	{
		tmp = tab[size - 1 - n];
		tab[size - 1 - n] = tab[n];
		tab[n] = tmp;
		n++;
	}
}
