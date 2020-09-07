/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_flag_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:10:16 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 15:15:35 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	get_flag_info_case_dot(char *buffer, int i, flag *flag_info, va_list ap)
{
	int pos;

	pos = i + 1;
	flag_info->flag_dot = TRUE;
	if (ft_isdigit(buffer[pos]))
		flag_info->flag_dot_precision = ft_atoi(buffer + pos);
	else if (buffer[pos] == '*')
	{
		flag_info->flag_dot_precision = va_arg(ap, int);
		if (flag_info->flag_dot_precision < 0)
		{
			flag_info->flag_dot_precision = -1;
			flag_info->flag_dot = FALSE;
		}
	}
}

void	get_flag_info_case_width(flag *flag_info, va_list ap)
{
	flag_info->flag_width_isTrue = TRUE;
	flag_info->flag_width = va_arg(ap, int);
	if (flag_info->flag_width < 0)
	{
		flag_info->flag_width *= -1;
		flag_info->flag_minus = TRUE;
		flag_info->flag_zero = FALSE;
	}
}

void	get_flag_info_case_left(flag *flag_info)
{
	flag_info->flag_minus = TRUE;
	flag_info->flag_zero = FALSE;
}

void	get_flag_info_case_zero(flag *flag_info)
{
	flag_info->flag_zero = TRUE;
}

void	get_flag_info_case_digit(char *buffer, int i, flag *flag_info)
{
	flag_info->flag_width_isTrue = TRUE;
	flag_info->flag_width = ft_atoi(buffer + i);
}
