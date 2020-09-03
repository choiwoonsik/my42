/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:13:36 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/03 21:50:49 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//						문자열 출력 경우						//

flag	treat_str_flag(char *str, flag flag_info)
{
	//정밀도는 없고 보장된 폭만 있는 경우
	if (flag_info.flag_width_isTrue == TRUE && flag_info.flag_dot == FALSE)
	{
		//폭이 문자열보다 작으면 의미 없음
		if (flag_info.flag_width <= (int)ft_strlen(str)){
			flag_info.flag_dot_precision = (int)ft_strlen(str);
			flag_info.flag_width = FALSE;
		}
		else
			flag_info.flag_dot_precision = flag_info.flag_width;
	}
	else if (flag_info.flag_width_isTrue == FALSE && flag_info.flag_dot == FALSE)
		flag_info.flag_dot_precision = (int)ft_strlen(str);
	//정밀도가 있고, 폭도 있는 경우 / 폭이 정밀도 미만라면 폭은 역활이 없다
	//폭이 정밀도 보다 작다면 폭은 의미 없음
	if (flag_info.flag_width < flag_info.flag_dot_precision && flag_info.flag_width_isTrue == TRUE)
		flag_info.flag_width_isTrue = FALSE;
	//정밀도가 문자열보다 크다면 정밀도는 역활이 없다
	if (flag_info.flag_dot_precision > (int)ft_strlen(str)) {
		flag_info.flag_dot_precision = (int)ft_strlen(str);
		flag_info.flag_dot = FALSE;
	}
	return (flag_info);
}

//좌로 붙여서 출력 혹은 우로 붙여서 출력
void	case_str_left_right(char* str, flag flag_info)
{
	if (flag_info.flag_minus)
	{
		ft_wirte_all(str, flag_info.flag_dot_precision);
		flag_info.flag_width -= flag_info.flag_dot_precision;
		while (flag_info.flag_width-- > 0)
		{
			ft_putchar(' ');
		}
	}
	else
	{
		flag_info.flag_width -= flag_info.flag_dot_precision;
		while (flag_info.flag_width-- > 0)
		{
			ft_putchar(' ');
		}
		ft_wirte_all(str, flag_info.flag_dot_precision);
	}
}

int		case_str_print(char* str, flag flag_info)
{
	int len_count;

	if (!str)
		str = "(null)";
	// printf("check ->%d    %d    %d  \n", flag_info.flag_width, flag_info.flag_dot, flag_info.flag_dot_precision);
	flag_info = treat_str_flag(str, flag_info);
	//폭이 지정되었고, 지정된 폭이 정밀도보다 크고, 정밀도가 문자열의 길이 미만일 경우 -> 폭이 젤 크고 정밀도가 문자열의 길이 안에서 설정된 경우
	if (flag_info.flag_width_isTrue == TRUE && flag_info.flag_dot == TRUE)
	{
		//좌, 우로정렬
		len_count = flag_info.flag_width;
		case_str_left_right(str, flag_info);
	}
	// 폭은 true 정밀도는 false -> 폭이 문자열보다 긴 경우 폭을 보장하며 작은경우는 그냥 출력 ( ' ' 빈칸으로 보장한다 )
	else if (flag_info.flag_width_isTrue == TRUE && flag_info.flag_dot == FALSE)
	{
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
	}
	// 폭은 false 정밀도만 true -> 정밀도만큼만 출력
	// 폭, 정밀도 false -> 그냥 문자열만 출력
	else
		len_count = ft_wirte_all(str, flag_info.flag_dot_precision);
	return (len_count);
}