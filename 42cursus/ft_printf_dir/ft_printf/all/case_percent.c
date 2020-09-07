/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:20:12 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 13:40:01 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	case_percent_left_right(char *str_int, flag flag_info)
{
	if (flag_info.flag_minus)
	{
		ft_wirte_all(str_int, 1);
		flag_info.flag_width -= 1;
		while (flag_info.flag_width-- > 0)
		{
			if (flag_info.flag_zero == TRUE)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	else
	{
		flag_info.flag_width -= 1;
		while (flag_info.flag_width-- > 0)
		{
			if (flag_info.flag_zero == TRUE)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_wirte_all(str_int, 1);
	}
}

flag	treat_percent_flag(flag flag_info)
{
	if (flag_info.flag_width <= 1)
		flag_info.flag_width_isTrue = FALSE;
	return (flag_info);
}

int		case_percent_print(flag flag_info)
{
	int		len_count;

	len_count = 0;
	flag_info = treat_percent_flag(flag_info);
	if (flag_info.flag_width_isTrue == TRUE)
	{
		len_count += flag_info.flag_width;
		case_percent_left_right("%", flag_info);
	}
	else
		len_count += ft_wirte_all("%", 1);
	return (len_count);
}
