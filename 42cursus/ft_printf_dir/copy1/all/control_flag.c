/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:08:00 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 15:20:11 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

flag	flag_start(void)
{
	flag	flag_info;

	flag_info.flag_dot = FALSE;
	flag_info.flag_dot_precision = 0;
	flag_info.flag_minus = FALSE;
	flag_info.flag_zero = FALSE;
	flag_info.flag_width = 0;
	flag_info.flag_width_isTrue = FALSE;
	flag_info.flag_type = FALSE;
	flag_info.flag_isMinus = FALSE;
	return (flag_info);
}

int		get_flag_info(char *buffer, int i, flag *flag_info, va_list ap)
{
	while (buffer[i])
	{
		if ((!isValid_flag(buffer[i]) &&
			!ft_isdigit(buffer[i])) && !isValid_type(buffer[i]))
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
		if (ft_isdigit(buffer[i]) && !flag_info->flag_width_isTrue
			&& !flag_info->flag_dot && buffer[i] != '0')
			get_flag_info_case_digit(buffer, i, flag_info);
		if (isValid_type(buffer[i]))
			break ;
		i++;
	}
	return (i);
}
