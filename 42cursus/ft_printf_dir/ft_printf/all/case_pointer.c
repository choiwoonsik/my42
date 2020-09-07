/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:19:25 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 13:38:45 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		case_pointer_precision_print(char *string_int, flag flag_info)
{
	int		len_count;

	len_count = 0;
	if (!flag_info.flag_isMinus)
	{
		len_count += 2;
		write(1, "0x", 2);
	}
	len_count += ft_wirte_all(string_int, (int)ft_strlen(string_int));
	return (len_count);
}

void	case_pointer_left_right(char *str_int, flag flag_info)
{
	if (flag_info.flag_minus)
	{
		case_pointer_precision_print(str_int, flag_info);
		flag_info.flag_width -= (int)ft_strlen(str_int) + 2;
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
	}
	else
	{
		flag_info.flag_width -= (int)ft_strlen(str_int) + 2;
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
		case_pointer_precision_print(str_int, flag_info);
	}
}

flag	treat_pointer_flag(char *str_int, flag flag_info)
{
	if (flag_info.flag_width <= (int)ft_strlen(str_int))
		flag_info.flag_width_isTrue = FALSE;
	if (flag_info.flag_dot == TRUE)
		flag_info.flag_dot = FALSE;
	return (flag_info);
}

char	*case_pointer_make_str(unsigned long long integer,
		int *len_count, flag *flag_info)
{
	char	*string_int;
	char	*copy;

	flag_info->flag_isMinus = FALSE;
	copy = ft_pointer_itoa(integer);
	if (flag_info->flag_width <= (int)ft_strlen(copy) + 2)
	{
		write(1, "0x", 2);
		*len_count += 2;
		flag_info->flag_isMinus = TRUE;
		flag_info->flag_width_isTrue = FALSE;
		flag_info->flag_dot_precision = (int)ft_strlen(copy) + 2;
	}
	string_int = ft_pointer_itoa(integer);
	return (string_int);
}

int		case_pointer_print(unsigned long long pointer, flag flag_info)
{
	char	*string_pointer;
	int		len_count;

	len_count = 0;
	string_pointer = case_pointer_make_str(pointer, &len_count, &flag_info);
	flag_info = treat_pointer_flag(string_pointer, flag_info);
	if (flag_info.flag_width_isTrue == TRUE)
	{
		len_count += flag_info.flag_width;
		flag_info.flag_dot_precision = (int)ft_strlen(string_pointer);
		case_pointer_left_right(string_pointer, flag_info);
	}
	else
		len_count += case_pointer_precision_print(string_pointer, flag_info);
	free(string_pointer);
	return (len_count);
}
