/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 22:20:08 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/04 22:45:50 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		return_plus_minus(char *str, int *minus)
{
	int		n;

	n = 0;
	while (str[n] == ' ' || (str[n] <= 13 && str[n] >= 9))
		n++;
	while (str[n] == '+' || str[n] == '-')
	{
		if (str[n] == '-')
			(*minus) *= -1;
		n++;
	}
	return (n);
}

int		make_num(char *str, int *val)
{
	int		n;

	n = 0;
	while (str[n] <= '9' && str[n] >= '0')
	{
		if (str[n + 1] <= '9' && str[n + 1] >= '0')
		{
			*val += str[n] - '0';
			*val *= 10;
		}
		else
		{
			*val += str[n] - '0';
		}
		n++;
	}
	return (*val);
}

int		ft_atoi(char *str)
{
	int		plus_minus;
	int		return_val;
	int		start;

	start = 0;
	plus_minus = 1;
	return_val = 0;
	start = return_plus_minus(str, &plus_minus);
	str += start;
	make_num(str, &return_val);
	return_val *= plus_minus;
	return (return_val);
}
