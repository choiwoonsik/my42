/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:22:21 by choeunsig         #+#    #+#             */
/*   Updated: 2020/08/15 20:04:42 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void VarFunc (int Fix, ...)
{
	va_list ap;
	va_start(ap, Fix);
	while (/*모든 인수를 다 읽을 때까지*/) 
	{
		va_arg(ap, /*인수타입*/);
	}
	va_end(ap);
}

t_flag		ft_flag_init(void)
{
	t_flag		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.width = 0;
	flags.type = 0;
	return (flags);
}

int			ft_flag_patch(const char *saved, va_list ap, int start, t_flag *flags)
{
	while (saved[start])
	{
		if (!ft_is_flag(saved[start]) && (!ft_is_type(saved[start]))
		&& ft_isdigit(saved[start]))
			break;
		if (saved[start] == '-')
			*flags = ft_flag_minus(*flags);
		if (saved[start] == '0')
			return (c);
		if (saved[start] == '.')
			return (c);
		if (saved[start] == '*')
			return (c);
		}
}

int			ft_isValid_Str(const char *saved, va_list ap)
{
	int		i;
	int		byte_count;
	t_flag	flags;

	i = 0;
	byte_count = 0;
	while(1)
	{
		flags = ft_flag_init();
		//빈문자열의 경우
		if(saved[i] == '\0')
			break ;
		//%를 만나고 뒤에 문자열이 더 있는경우
		else if (saved[i] == '%' && saved[i + 1] != '\0')
		{
			i = ft_flag_patch(saved, ap, ++i, &flags);
		}
		//아직 %를 만나기전이지만 문자열의 길이는 측정하는 경우
		else if (saved[i] != '%')
			byte_count++;
		i++;
	}
	return (byte_count);
}

int     	ft_printf(const char *String, ...)
{
	//printf함수는 입력받은 문자열의 길이를 반환한다
	va_list 	ap; 		//가변인수를 읽기위한 포인터 변수 선언 , 현재 읽고있는 번지를 기억하기위한 변수
	int			byte_count;	//입력받은 문자열의 길이를 체크
	const char	*saved;		//입력받은 문자열을 보관

	saved = ft_strdup(String);
	byte_count = 0;
	va_start(ap, String);
	byte_count += ft_isValid_Str(saved, ap); //문자열의 길이의 합
	va_end(ap);
	free((char *)saved);
	return (byte_count);
}