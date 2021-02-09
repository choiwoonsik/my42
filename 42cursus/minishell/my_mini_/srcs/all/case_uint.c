/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:17:50 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 18:29:55 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		case_uint_precision_print(char *string_int, t_flag flag_info)
{
	int		zero_cnt;
	int		len_count;

	zero_cnt = flag_info.flag_dot_precision - (int)ft_strlen(string_int);
	len_count = zero_cnt;
	if (zero_cnt > 0 && flag_info.flag_dot == TRUE)
	{
		while (zero_cnt-- > 0)
			ft_putchar('0');
		len_count += ft_wirte_all(string_int, (int)ft_strlen(string_int));
	}
	else
		len_count = ft_wirte_all(string_int, (int)ft_strlen(string_int));
	return (len_count);
}

void	case_uint_left_right(char *str_int, t_flag flag_info)
{
	char	c;

	if (flag_info.flag_minus)
	{
		case_uint_precision_print(str_int, flag_info);
		flag_info.flag_width -= flag_info.flag_dot_precision;
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
	}
	else
	{
		flag_info.flag_width -= flag_info.flag_dot_precision;
		c = flag_info.flag_zero ? '0' : ' ';
		while (flag_info.flag_width-- > 0)
			ft_putchar(c);
		case_uint_precision_print(str_int, flag_info);
	}
}

t_flag	treat_uint_flag(char *str_int, t_flag flag_info)
{
	if (flag_info.flag_width <= (int)ft_strlen(str_int))
		flag_info.flag_width_istrue = FALSE;
	if (flag_info.flag_zero == TRUE &&
		(flag_info.flag_dot == TRUE || flag_info.flag_minus == TRUE))
		flag_info.flag_zero = FALSE;
	if (flag_info.flag_dot_precision <= (int)ft_strlen(str_int))
	{
		flag_info.flag_dot = FALSE;
		flag_info.flag_dot_precision = (int)ft_strlen(str_int);
	}
	if (flag_info.flag_width <= flag_info.flag_dot_precision)
		flag_info.flag_width_istrue = FALSE;
	return (flag_info);
}

char	*case_uint_make_str(unsigned int u_integer, t_flag flag_info)
{
	char	*string_uint;

	if (u_integer == 0 && flag_info.flag_dot == TRUE)
		string_uint = ft_strdup("");
	else
	{
		u_integer = (unsigned int)(4294967295 + 1 + u_integer);
		string_uint = ft_u_itoa(u_integer);
	}
	return (string_uint);
}

int		case_uint_print(unsigned int u_integer, t_flag flag_info)
{
	char	*string_uint;
	int		len_count;

	len_count = 0;
	string_uint = case_uint_make_str(u_integer, flag_info);
	flag_info = treat_uint_flag(string_uint, flag_info);
	if (flag_info.flag_width_istrue == TRUE && flag_info.flag_dot == TRUE)
	{
		len_count += flag_info.flag_width;
		case_uint_left_right(string_uint, flag_info);
	}
	else if (flag_info.flag_width_istrue == TRUE)
	{
		len_count += flag_info.flag_width;
		flag_info.flag_dot_precision = (int)ft_strlen(string_uint);
		case_uint_left_right(string_uint, flag_info);
	}
	else
	{
		len_count += case_uint_precision_print(string_uint, flag_info);
	}
	free(string_uint);
	return (len_count);
}
