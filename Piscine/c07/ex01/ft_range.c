/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 13:34:12 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/14 16:59:59 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*re_int;
	int		i;

	i = 0;
	re_int = (int*)malloc(sizeof(int) * (max - min));
	if (min >= max)
		return (0);
	while (min < max)
	{
		re_int[i] = min;
		i++;
		min++;
	}
	return (re_int);
}
