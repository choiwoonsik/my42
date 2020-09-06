/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:19:25 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/06 12:35:21 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//						숫자 출력 경우						//

int		case_pointer_precision_print(char *string_int, flag flag_info)
{
	//정밀도가 숫자의 길이보다 긴 경우 -->> 0을 출력하고 숫자 출력	
	int		len_count;

	len_count = 0;
	if (!flag_info.flag_isMinus){
		len_count += 2;
		write(1, "0x", 2);
	}
	len_count += ft_wirte_all(string_int, (int)ft_strlen(string_int));
	return (len_count);
}

void	case_pointer_left_right(char *str_int, flag flag_info)
{
	//문제되는 부분
	//printf("\n\nthis is problem\n\n");
	int n = 0;
	if (flag_info.flag_minus)
	{
		case_pointer_precision_print(str_int, flag_info);
		flag_info.flag_width -= (int)ft_strlen(str_int) + 2;
		while (flag_info.flag_width-- > 0){
			ft_putchar(' ');
		}
	}
	else
	{
		flag_info.flag_width -= (int)ft_strlen(str_int) + 2;
		while (flag_info.flag_width-- > 0){
			ft_putchar(' ');
		}
		case_pointer_precision_print(str_int, flag_info);
	}
}

flag	treat_pointer_flag(char *str_int, flag flag_info)
{
	//폭이 문자열보다 짧거나 같다면
	if (flag_info.flag_width <= (int)ft_strlen(str_int))
		flag_info.flag_width_isTrue = FALSE;
	//정밀도가 문자열보다 짧거나 같다면
	// if (flag_info.flag_dot_precision <= (int)ft_strlen(str_int)){
	// 	flag_info.flag_dot = FALSE;
	// 	flag_info.flag_dot_precision = (int)ft_strlen(str_int) + 2;
	// }
	if (flag_info.flag_dot == TRUE)
		flag_info.flag_dot = FALSE;
	//정밀도가 폭보다 크거나 같다면
	// if (flag_info.flag_width <= flag_info.flag_dot_precision)
	// 	flag_info.flag_width_isTrue = FALSE;
	return flag_info;
}

char	*case_pointer_makeStr(unsigned long long integer, int *len_count, flag *flag_info)
{
	char	*string_int;
	char	*copy;
	flag_info->flag_isMinus = FALSE;
	copy = ft_pointer_itoa(integer);
	//폭이 수의 길이가 출력문장의 길이 + 2보다 작다면 - 바로 출력
	if(flag_info->flag_width <= (int)ft_strlen(copy) + 2){ //폭이 주소 길이 + 2보다 작거나 같다면 바로 출력
		write(1, "0x", 2);
		*len_count += 2;
		flag_info->flag_isMinus = TRUE;
		flag_info->flag_dot_precision = (int)ft_strlen(copy) + 2;
	}
	string_int = ft_pointer_itoa(integer);
	return (string_int);
}

int		case_pointer_print(unsigned long long pointer, flag flag_info)
{
	char	*string_pointer;
	int		len_count;

	//printf("width>>%d", flag_info.flag_width);
	len_count = 0;
	string_pointer = case_pointer_makeStr(pointer, &len_count, &flag_info);
	flag_info = treat_pointer_flag(string_pointer, flag_info);
	//폭과 정밀도 둘다 있는 경우
	if (flag_info.flag_width_isTrue == TRUE)
	{
		///printf("(case2)\n");
		//printf("width>>%d", flag_info.flag_width);
		len_count += flag_info.flag_width;
		flag_info.flag_dot_precision = (int)ft_strlen(string_pointer);
		case_pointer_left_right(string_pointer, flag_info);
	}
	//폭이 지정되지 않았거나, 그폭이 출력할 수의 길이 보다 짧은경우
	else
	{
		len_count += case_pointer_precision_print(string_pointer, flag_info);
	}
	free(string_pointer);
	return (len_count);
}
