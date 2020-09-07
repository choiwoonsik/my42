/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:23:34 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 16:55:17 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		make_num(const char *str, int minus, int *len)
{
	int		i;
	int		num;

	num = 0;
	i = 0;
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
		(*len)++;
	}
	return (num * minus);
}

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
	num = make_num(&str[i], minus, &len);
	if (len >= 20)
	{
		if (minus < 0)
			return (0);
		return (-1);
	}
	return (int)(num);
}
