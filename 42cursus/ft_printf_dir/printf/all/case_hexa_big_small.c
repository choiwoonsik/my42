/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_hexa_big_small.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:19:01 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 13:48:14 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		case_hexa_precision_print(char *string_int, flag flag_info)
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

void	case_hexa_left_right(char *str_int, flag flag_info)
{
	char	c;

	if (flag_info.flag_minus)
	{
		case_hexa_precision_print(str_int, flag_info);
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
		case_hexa_precision_print(str_int, flag_info);
	}
}

flag	treat_hexa_flag(char *str_int, flag flag_info)
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

char	*case_hexa_make_str(unsigned int hexa, int is_big, flag *flag_info)
{
	char	*string_hexa;
	int		n;

	n = 0;
	if (hexa == 0 && flag_info->flag_dot == TRUE)
		string_hexa = ft_strdup("");
	else
	{
		string_hexa = ft_hexa_itoa(hexa);
		if (is_big)
		{
			while (string_hexa[n] != '\0')
			{
				string_hexa[n] = ft_toupper(string_hexa[n]);
				n++;
			}
		}
	}
	return (string_hexa);
}

int		case_hexa_print(unsigned int hexa, int is_big, flag flag_info)
{
	char	*string_hexa;
	int		len_count;

	len_count = 0;
	string_hexa = case_hexa_make_str(hexa, is_big, &flag_info);
	flag_info = treat_hexa_flag(string_hexa, flag_info);
	if (flag_info.flag_width_isTrue == TRUE && flag_info.flag_dot == TRUE)
	{
		len_count += flag_info.flag_width;
		case_hexa_left_right(string_hexa, flag_info);
	}
	else if (flag_info.flag_width_isTrue == TRUE)
	{
		len_count += flag_info.flag_width;
		flag_info.flag_dot_precision = (int)ft_strlen(string_hexa);
		case_hexa_left_right(string_hexa, flag_info);
	}
	else
		len_count += case_hexa_precision_print(string_hexa, flag_info);
	free(string_hexa);
	return (len_count);
}
