/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:51:49 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/12 11:10:37 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		mk_start_point(const char *str, int* minus)
{
	int		n;

	n = 0;
	*minus = 1;
	while (str[n] == ' ' || (str[n] <= 13 && str[n] >= 9))
		n++;
	while (str[n] == '+' || str[n] == '-')
	{
		if (str[n] == '-')
			*minus *= -1;
		n++;
	}
	return (n);
}

int		mk_real_num(const char *str)
{
	int		n;
	int		re_val;

	re_val = 0;
	n = 0;
	while (str[n] <= '9' && str[n] >= '0')
	{
		if (str[n + 1] <= '9' && str[n + 1] >= '0')
		{
			re_val += str[n] - '0';
			re_val *= 10;
		}
		else
			re_val += str[n] - '0';
		n++;
	}
	return (re_val);
}

int		ft_atoi(const char *str)
{
	int		minus;
	int		num;
	int		start;

	start = mk_start_point(str, &minus);
	str += start;
	num = mk_real_num(str);
	return (num * minus);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%d\n", ft_atoi("  		++++---++123456ZZZZzz"));
	
}