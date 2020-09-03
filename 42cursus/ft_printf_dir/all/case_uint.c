/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:17:50 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/02 21:05:24 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//						숫자 출력 경우						//

int		case_uint_precision_print(char *string_int, flag flag_info)
{
	int 	zero_cnt;
	int		len_count;
	//정밀도가 숫자의 길이보다 긴 경우 -->> 0을 출력하고 숫자 출력
	zero_cnt = flag_info.flag_dot_precision - ft_strlen(string_int);
	len_count = zero_cnt;
	if (zero_cnt > 0 && flag_info.flag_dot == TRUE)
	{
		while (zero_cnt-- > 0)
			ft_putchar('0');
		len_count += ft_wirte_all(string_int, ft_strlen(string_int));
	}
	//그냥 숫자만 출력
	else
		len_count = ft_wirte_all(string_int, ft_strlen(string_int));
	return (len_count);
}

void	case_uint_left_right(char *str_int, flag flag_info)
{
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
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
		case_uint_precision_print(str_int, flag_info);
	}
}

flag	treat_uint_flag(char *str_int, flag flag_info)
{
	//폭이 문자열보다 짧거나 같다면
	if (flag_info.flag_width <= ft_strlen(str_int))
		flag_info.flag_width_isTrue = FALSE;
	//정밀도가 문자열보다 짧거나 같다면
	if (flag_info.flag_dot_precision <= ft_strlen(str_int)){
		flag_info.flag_dot = FALSE;
		flag_info.flag_dot_precision = ft_strlen(str_int);
	}
	//정밀도가 폭보다 크거나 같다면
	if (flag_info.flag_width <= flag_info.flag_dot_precision)
		flag_info.flag_width_isTrue = FALSE;
	return flag_info;
}

int		case_uint_print(unsigned int u_integer, va_list ap, flag flag_info)
{
	char	*string_uint;
	int		len_count;

	u_integer = (unsigned int)(4294967295 + 1 + u_integer);
	len_count = 0;
	string_uint = ft_u_itoa(u_integer);
	flag_info = treat_uint_flag(string_uint, flag_info);

	//폭과 정밀도 둘다 있는 경우
	if (flag_info.flag_width_isTrue == TRUE && flag_info.flag_dot == TRUE)
	{
		len_count += flag_info.flag_width;
		case_uint_left_right(string_uint, flag_info);
	}
	//정밀도는 지정되있지 않고 폭만 있는 경우
	else if (flag_info.flag_width_isTrue == TRUE)
	{
		len_count += flag_info.flag_width;
		flag_info.flag_dot_precision = ft_strlen(string_uint);
		case_uint_left_right(string_uint, flag_info);
	}
	//폭이 지정되지 않았거나, 그폭이 출력할 수의 길이 보다 짧은경우
	else
	{
		len_count += case_uint_precision_print(string_uint, flag_info);
	}
	free(string_uint);
	return (len_count);
}
