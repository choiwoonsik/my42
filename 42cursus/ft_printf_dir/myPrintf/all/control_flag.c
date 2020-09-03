/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:08:00 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/02 16:52:29 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//				flag 체크 부분			//

flag	flag_start(void)
{
	flag	flag_info;

	flag_info.flag_dot = FALSE;
	flag_info.flag_dot_precision = 0;
	flag_info.flag_minus = FALSE;
	flag_info.flag_zero = FALSE;
	flag_info.flag_star = FALSE;
	flag_info.flag_width = -1;
	flag_info.flag_width_isTrue = FALSE;
	flag_info.flag_type = FALSE;
	flag_info.flag_isMinus = FALSE;
	return (flag_info);
}

//				%를 만난 이후 flag처리 부분			//

int		get_flag_info(char* buffer, int i, flag *flag_info, va_list ap)
{
	while (buffer[i])
	{
		if ((!isValid_flag(buffer[i]) && !ft_isdigit(buffer[i])) && !isValid_type(buffer[i]))
			break;
		// 0 플래그 단, 정밀도가 정수에 대해 지정되거나 - 플래그가 지정되면 무시된다
		if (buffer[i] == '0' && flag_info->flag_minus == FALSE && flag_info->flag_dot == FALSE) 
		{
			flag_info->flag_zero = TRUE;
		}	
		// - 플래그
		if (buffer[i] == '-')
		{
			//좌로 정렬할 경우 제로플래그가 있어도 0이 출력되지 않는다
			flag_info->flag_minus = TRUE;
			flag_info->flag_zero = FALSE;
		}
		// . 플래그
		if (buffer[i] == '.' && !flag_info->flag_dot)
		{
			int pos;

			pos = i + 1;
			flag_info->flag_dot = TRUE;
			// 정밀도가 . 뒤에 바로 정수로 나오는 경우
			if (ft_isdigit(buffer[pos])) {
				flag_info->flag_dot_precision = ft_atoi(buffer + pos);
			}
			// 정밀도가 . 뒤에 *를 통해 정수로 치환되는 경우
			else if (buffer[pos] == '*')
			{
				flag_info->flag_dot_precision = va_arg(ap, int);
				if (flag_info->flag_dot_precision < 0)
					flag_info->flag_dot_precision = 0;
			}
		}
		// * 플래그
		if (buffer[i] == '*')
		{
			flag_info->flag_star = TRUE;
			flag_info->flag_width_isTrue = TRUE;
			flag_info->flag_width = va_arg(ap, int);
			if (flag_info->flag_width < 0)
			{
				flag_info->flag_width *= -1;
				flag_info->flag_minus = TRUE;
				flag_info->flag_zero = FALSE;
			}
		}
		if (ft_isdigit(buffer[i]) && !flag_info->flag_width_isTrue && !flag_info->flag_dot) 
		{
			flag_info->flag_width_isTrue = TRUE;
			flag_info->flag_width = ft_atoi(buffer + i);
		}
		if (isValid_type(buffer[i]))
		{
			break;
		}
		i++;
	}
	return (i);
}