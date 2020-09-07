/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_int_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:54:42 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 14:04:24 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*case_int_make_str_inner(int integer, int *len_count, flag *flag_info)
{
	char	*string_int;
	char	*copy;

	flag_info->flag_isMinus = TRUE;
	copy = ft_u_itoa(integer * -1);
	if (flag_info->flag_dot_precision > (int)ft_strlen(copy)
		&& flag_info->flag_width <= flag_info->flag_dot_precision)
	{
		*len_count += ft_putchar('-');
		flag_info->flag_width -= 1;
		flag_info->flag_isMinus = FALSE;
	}
	if (flag_info->flag_dot == FALSE && flag_info->flag_zero == TRUE)
	{
		*len_count += ft_putchar('-');
		flag_info->flag_width -= 1;
		flag_info->flag_isMinus = FALSE;
	}
	string_int = ft_u_itoa(integer * -1);
	return (string_int);
}

char	*case_int_make_str(int integer, int *len_count, flag *flag_info)
{
	char	*string_int;

	if (integer < 0)
		string_int = case_int_make_str_inner(integer, len_count, flag_info);
	else if (integer == 0 && flag_info->flag_dot == TRUE)
		string_int = ft_strdup("");
	else
		string_int = ft_itoa(integer);
	return (string_int);
}
