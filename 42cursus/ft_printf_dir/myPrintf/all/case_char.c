/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:20:12 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/04 19:13:06 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	case_char_left_right(char str_int, flag flag_info)
{
	if (flag_info.flag_minus)
	{
		write(1, &str_int, 1);
		flag_info.flag_width -= 1;
		while (flag_info.flag_width-- > 0)
		{
				ft_putchar(' ');
		}
	}
	else
	{
		flag_info.flag_width -= 1;
		while (flag_info.flag_width-- > 0)
		{
				ft_putchar(' ');
		}
		write(1, &str_int, 1);
	}
}

flag	treat_char_flag(flag flag_info)
{
	//폭이 문자열보다 짧거나 같다면
	if (flag_info.flag_width <= 1)
		flag_info.flag_width_isTrue = FALSE;
	return flag_info;
}

int		case_char_print(char character, flag flag_info)
{
	int		len_count;

	len_count = 0;
	flag_info = treat_char_flag(flag_info);
	//정밀도는 지정되있지 않고 폭만 있는 경우
	if (flag_info.flag_width_isTrue == TRUE)
	{
		len_count += flag_info.flag_width;
		case_char_left_right(character, flag_info);
	}
	//폭이 지정되지 않았거나, 그폭이 출력할 수의 길이 보다 짧은경우
	else
		write(1, &character, 1);
	return (len_count);
}