/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:15:19 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/03 21:52:26 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//						숫자 출력 경우						//

int		case_int_precision_print(char *string_int, flag flag_info)
{
	int 	zero_cnt;
	int		len_count;
	//정밀도가 숫자의 길이보다 긴 경우 -->> 0을 출력하고 숫자 출력
	zero_cnt = flag_info.flag_dot_precision - (int)ft_strlen(string_int);
	len_count = zero_cnt;
	if (zero_cnt > 0 && flag_info.flag_dot == TRUE)
	{
		while (zero_cnt-- > 0)
			ft_putchar('0');
		if (flag_info.flag_isMinus)
			ft_putchar('-');
		len_count += ft_wirte_all(string_int, (int)ft_strlen(string_int));
	}
	//그냥 숫자만 출력
	else
	{
		if (flag_info.flag_isMinus)
			ft_putchar('-');
		len_count = ft_wirte_all(string_int, (int)ft_strlen(string_int));
	}
	if (flag_info.flag_isMinus)
		len_count += 1;
	return (len_count);
}

void	case_int_left_right(char *str_int, flag flag_info)
{
	if (flag_info.flag_minus)
	{
		case_int_precision_print(str_int, flag_info);
		flag_info.flag_width -= flag_info.flag_dot_precision;
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
	}
	else
	{
		flag_info.flag_width -= flag_info.flag_dot_precision;
		while (flag_info.flag_width-- > 0)
			ft_putchar(' ');
		case_int_precision_print(str_int, flag_info);
	}
}

flag	treat_int_flag(char *str_int, flag flag_info)
{
	//폭이 문자열보다 짧거나 같다면
	if (flag_info.flag_width <= (int)ft_strlen(str_int))
		flag_info.flag_width_isTrue = FALSE;
	//정밀도가 문자열보다 짧거나 같다면
	if (flag_info.flag_dot_precision <= (int)ft_strlen(str_int)){
		flag_info.flag_dot = FALSE;
		flag_info.flag_dot_precision = (int)ft_strlen(str_int);
	}
	//정밀도가 폭보다 크거나 같다면
	if (flag_info.flag_width <= flag_info.flag_dot_precision)
		flag_info.flag_width_isTrue = FALSE;
	return flag_info;
}

char	*case_int_makeStr(int integer, int *len_count, flag *flag_info)
{
	char	*string_int;
	char	*copy;
	//정밀도가 없는 경우 바로 출력
	if (integer < 0)
	{
		flag_info->flag_isMinus = TRUE;
		copy = ft_u_itoa(integer);
		//정밀도가 수의 길이보다 크다면 바로 - 출력
		if(flag_info->flag_dot_precision > (int)ft_strlen(copy)){
			*len_count += ft_putchar('-');
			flag_info->flag_width -= 1;
			flag_info->flag_isMinus = FALSE;
		}
		string_int = ft_u_itoa(integer * -1);
	}
	else
		string_int = ft_itoa(integer);
	return (string_int);
}

int		case_int_print(int integer, flag flag_info)
{
	char	*string_int;
	int		len_count;

	len_count = 0;
	string_int = case_int_makeStr(integer, &len_count, &flag_info);
	flag_info = treat_int_flag(string_int, flag_info);
	//폭과 정밀도 둘다 있는 경우
	if (flag_info.flag_width_isTrue == TRUE && flag_info.flag_dot == TRUE)
	{
		len_count += flag_info.flag_width;
		case_int_left_right(string_int, flag_info);
	}
	//정밀도는 지정되있지 않고 폭만 있는 경우
	else if (flag_info.flag_width_isTrue == TRUE)
	{
		len_count += flag_info.flag_width;
		flag_info.flag_dot_precision = (int)ft_strlen(string_int);
		case_int_left_right(string_int, flag_info);
	}
	//폭이 지정되지 않았거나, 그폭이 출력할 수의 길이 보다 짧은경우
	else
	{
		//printf("폭> %d  정밀도> %d ", flag_info.flag_width, flag_info.flag_dot_precision);
		len_count += case_int_precision_print(string_int, flag_info);
	}
	free(string_int);
	return (len_count);
}