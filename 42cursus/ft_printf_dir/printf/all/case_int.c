/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:15:19 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 16:25:14 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	c_i_p_p_inner(int *len_count,
		int zero_cnt, char *string_int, flag *flag_info)
{
	if (flag_info->flag_width_isTrue && flag_info->flag_isMinus)
	{
		ft_putchar('-');
		flag_info->flag_isMinus = FALSE;
	}
	while (zero_cnt-- > 0)
		ft_putchar('0');
	if (flag_info->flag_isMinus)
		ft_putchar('-');
	*len_count += ft_wirte_all(string_int, (int)ft_strlen(string_int));
}

int		case_int_precision_print(char *string_int, flag flag_info)
{
	int		zero_cnt;
	int		len_count;

	zero_cnt = flag_info.flag_dot_precision - (int)ft_strlen(string_int);
	len_count = zero_cnt;
	if (zero_cnt > 0 && flag_info.flag_dot == TRUE)
		c_i_p_p_inner(&len_count, zero_cnt, string_int, &flag_info);
	else
	{
		if (flag_info.flag_isMinus)
			ft_putchar('-');
		len_count = ft_wirte_all(string_int, (int)ft_strlen(string_int));
	}
	if (flag_info.flag_isMinus)
		len_count += 1;
	return (len_count);
}

void	case_int_left_right(char *str_int, flag flag_info)
{
	int		is_minus;
	char	c;

	is_minus = flag_info.flag_isMinus ? 1 : 0;
	if (flag_info.flag_minus)
	{
		case_int_precision_print(str_int, flag_info);
		flag_info.flag_width -= flag_info.flag_dot_precision + is_minus;
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
	}
	else
	{
		flag_info.flag_width -= flag_info.flag_dot_precision + is_minus;
		c = flag_info.flag_zero ? '0' : ' ';
		while (flag_info.flag_width-- > 0)
			ft_putchar(c);
		case_int_precision_print(str_int, flag_info);
	}
}

flag	treat_int_flag(char *str_int, flag flag_info)
{
	if (flag_info.flag_width <= (int)ft_strlen(str_int))
		flag_info.flag_width_isTrue = FALSE;
	if (flag_info.flag_zero == TRUE
		&& (flag_info.flag_dot == TRUE || flag_info.flag_minus == TRUE))
		flag_info.flag_zero = FALSE;
	if (flag_info.flag_dot_precision <= (int)ft_strlen(str_int))
	{
		flag_info.flag_dot = FALSE;
		flag_info.flag_dot_precision = (int)ft_strlen(str_int);
	}
	if (flag_info.flag_width <= flag_info.flag_dot_precision)
		flag_info.flag_width_isTrue = FALSE;
	return (flag_info);
}

int		case_int_print(int integer, flag flag_info)
{
	char	*string_int;
	int		len_count;

	len_count = 0;
	string_int = case_int_make_str(integer, &len_count, &flag_info);
	flag_info = treat_int_flag(string_int, flag_info);
	if (flag_info.flag_width_isTrue == TRUE && flag_info.flag_dot == TRUE)
	{
		len_count += flag_info.flag_width;
		case_int_left_right(string_int, flag_info);
	}
	else if (flag_info.flag_width_isTrue == TRUE)
	{
		len_count += flag_info.flag_width;
		flag_info.flag_dot_precision = (int)ft_strlen(string_int);
		case_int_left_right(string_int, flag_info);
	}
	else
		len_count += case_int_precision_print(string_int, flag_info);
	free(string_int);
	return (len_count);
}
