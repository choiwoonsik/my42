/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:23:34 by groom             #+#    #+#             */
/*   Updated: 2020/07/09 19:44:10 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	num;
	int		len;

	i = 0;
	num = 0;
	len = 0;
	minus = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (str[i + 1] <= '9' && str[i + 1] >= '0')
		{
			num += (str[i] - '0');
			num *= 10;
		}
		else
			num += (str[i] - '0');
		i++;
		len++;
	}
	if (len >= 20)
	{
		if (minus < 0)
			return (0);
		else
			return (-1);
	}
	return (int)(num * minus);
}
