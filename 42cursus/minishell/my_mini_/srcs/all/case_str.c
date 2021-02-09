/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:13:36 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 20:17:49 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flag	treat_str_flag(char *str, t_flag flag_info)
{
	if (flag_info.flag_width_istrue == TRUE && flag_info.flag_dot == FALSE)
	{
		if (flag_info.flag_width <= (int)ft_strlen(str))
		{
			flag_info.flag_dot_precision = (int)ft_strlen(str);
			flag_info.flag_width_istrue = FALSE;
		}
		else
			flag_info.flag_dot_precision = flag_info.flag_width;
	}
	else if (flag_info.flag_width_istrue == FALSE
			&& flag_info.flag_dot == FALSE)
		flag_info.flag_dot_precision = (int)ft_strlen(str);
	if (flag_info.flag_width < flag_info.flag_dot_precision
		&& flag_info.flag_width_istrue == TRUE && !str)
		flag_info.flag_width_istrue = FALSE;
	if (flag_info.flag_dot_precision > (int)ft_strlen(str))
	{
		flag_info.flag_dot_precision = (int)ft_strlen(str);
		flag_info.flag_dot = FALSE;
	}
	return (flag_info);
}

void	case_str_left_right(char *str, t_flag flag_info)
{
	if (flag_info.flag_minus)
	{
		ft_wirte_all(str, flag_info.flag_dot_precision);
		flag_info.flag_width -= flag_info.flag_dot_precision;
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
	}
	else
	{
		flag_info.flag_width -= flag_info.flag_dot_precision;
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
		ft_wirte_all(str, flag_info.flag_dot_precision);
	}
}

int		case_str_print_inner(char *str, t_flag flag_info)
{
	int		len_count;

	len_count = 0;
	if (flag_info.flag_width > (int)ft_strlen(str))
	{
		len_count = flag_info.flag_width;
		case_str_left_right(str, flag_info);
	}
	else
	{
		flag_info.flag_dot_precision = (int)ft_strlen(str);
		len_count = ft_wirte_all(str, flag_info.flag_dot_precision);
	}
	return (len_count);
}

int		case_str_print(char *str, t_flag flag_info)
{
	int len_count;

	len_count = 0;
	if (!str)
		str = "(null)";
	flag_info = treat_str_flag(str, flag_info);
	if (flag_info.flag_width_istrue == TRUE && flag_info.flag_dot == TRUE)
	{
		len_count = flag_info.flag_width > flag_info.flag_dot_precision
		? flag_info.flag_width : flag_info.flag_dot_precision;
		case_str_left_right(str, flag_info);
	}
	else if (flag_info.flag_width_istrue == TRUE && flag_info.flag_dot == FALSE)
		len_count = case_str_print_inner(str, flag_info);
	else
		len_count = ft_wirte_all(str, flag_info.flag_dot_precision);
	return (len_count);
}
