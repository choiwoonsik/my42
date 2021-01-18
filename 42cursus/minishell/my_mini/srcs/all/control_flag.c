/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:08:00 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 19:09:45 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flag	flag_start(void)
{
	t_flag	flag_info;

	flag_info.flag_dot = FALSE;
	flag_info.flag_dot_precision = 0;
	flag_info.flag_minus = FALSE;
	flag_info.flag_zero = FALSE;
	flag_info.flag_width = 0;
	flag_info.flag_width_istrue = FALSE;
	flag_info.flag_type = FALSE;
	flag_info.flag_isminus = FALSE;
	return (flag_info);
}

int		is_valid_flag(char flag)
{
	return ((flag == '-') || (flag == '.') || (flag == '0') || (flag == '*'));
}

int		get_flag_info(const char *buffer, int i, t_flag *flag_info, va_list ap)
{
	while (buffer[i])
	{
		if ((!is_valid_flag(buffer[i]) &&
			!ft_isdigit(buffer[i])) && !is_valid_type(buffer[i]))
			break ;
		if (buffer[i] == '0' &&
			flag_info->flag_minus == FALSE && flag_info->flag_width == 0)
			get_flag_info_case_zero(flag_info);
		if (buffer[i] == '-')
			get_flag_info_case_left(flag_info);
		if (buffer[i] == '.' && !flag_info->flag_dot)
			get_flag_info_case_dot(buffer, i, flag_info, ap);
		if (buffer[i] == '*' && (flag_info->flag_dot == FALSE
			&& flag_info->flag_dot_precision != -1))
			get_flag_info_case_width(flag_info, ap);
		if (ft_isdigit(buffer[i]) && !flag_info->flag_width_istrue
			&& !flag_info->flag_dot && buffer[i] != '0')
			get_flag_info_case_digit(buffer, i, flag_info);
		if (is_valid_type(buffer[i]))
			break ;
		i++;
	}
	return (i);
}
