/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:02:41 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/03 22:00:45 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//				타입 및 케이스 체크 부분			//

int		isValid_flag(char flag)
{
	return ((flag == '-') || (flag == '.') || (flag == '0') || (flag == '*'));
}

int		isValid_type(char type)
{
	return ((type == 'c') || (type == 's') || (type == 'd') || (type == 'i') || (type == 'u')
	|| (type == 'x') || (type == 'X') || (type == 'p') || (type == '%'));
}

//				케이스 분류 부분			//

int		case_divide(char type, va_list ap, flag flag_info)
{
	int		len_count;

	//va_arg함수 - va_start 함수에 의해 설정된 string값에 자료형의 크기를 더한다
	if (type == 's')
		len_count = case_str_print(va_arg(ap, char*), flag_info);
	if (type == 'd' || type == 'i')
		len_count = case_int_print(va_arg(ap, int),flag_info);
	if (type == 'c')
		len_count = case_char_print(va_arg(ap, int));
	if (type == 'u')
		len_count = case_uint_print((unsigned int)va_arg(ap, unsigned int), flag_info);
	if (type == 'x')
		len_count = case_hexa_print(va_arg(ap, unsigned int), FALSE, flag_info);
	if (type == 'X')
		len_count = case_hexa_print(va_arg(ap, unsigned int), TRUE, flag_info);
	if (type == 'p')
		len_count = case_pointer_print(va_arg(ap, unsigned long long), flag_info);
	if (type == '%')
		len_count = case_percent_print();
	return (len_count);
}

//				문자열 출력 메인 부분			//

int		ft_printf(const char *format, ...)
{
	va_list ap;
	flag	flag_info;
	int		i;
	int		len_count;

	i = 0;
	len_count = 0;
	//fomat 주소값을 ap에 넣어준다
	va_start(ap, format);
	char *buffer = ft_strdup(format);
	while (1)
	{
		flag_info = flag_start();
		if (buffer[i] == '\0')
			break;
		else if (buffer[i] == '%' && buffer[i] != '\0')
		{
			i = get_flag_info(buffer, ++i, &flag_info, ap);
			// printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",  
			// flag_info.flag_dot,
			// flag_info.flag_dot_precision,
			// flag_info.flag_minus,
			// flag_info.flag_zero,
			// flag_info.flag_star,
			// flag_info.flag_width,
			// flag_info.flag_width_isTrue,
			// flag_info.flag_type);
			if (isValid_type(buffer[i]))
			{
				len_count += case_divide(buffer[i], ap, flag_info);
			}
			else if (buffer[i])
				len_count += ft_putchar(buffer[i]);
		}
		else if (buffer[i] != '%')
			len_count += ft_putchar(buffer[i]);
		i++;
	}
	va_end(ap);
	return (len_count);
}