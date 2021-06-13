/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:02:41 by choeunsig         #+#    #+#             */
/*   Updated: 2021/06/13 18:25:22 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int is_valid_type(char type)
{
	return ((type == 'c') || (type == 's') || (type == 'd') || (type == 'i') || (type == 'u') || (type == 'x') || (type == 'X') || (type == 'p') || (type == '%'));
}

int case_divide(char type, va_list ap, t_flag flag_info)
{
	int len_count;

	if (type == 's')
		len_count = case_str_print(va_arg(ap, char *), flag_info);
	if (type == 'd' || type == 'i')
		len_count = case_int_print(va_arg(ap, int), flag_info);
	if (type == 'c')
		len_count = case_char_print(va_arg(ap, int), flag_info);
	if (type == 'u')
		len_count = case_uint_print((unsigned int)
										va_arg(ap, unsigned int),
									flag_info);
	if (type == 'x')
		len_count = case_hexa_print(va_arg(ap, unsigned int), FALSE, flag_info);
	if (type == 'X')
		len_count = case_hexa_print(va_arg(ap, unsigned int), TRUE, flag_info);
	if (type == 'p')
		len_count = case_pointer_print(
			va_arg(ap, unsigned long long), flag_info);
	if (type == '%')
		len_count = case_percent_print(flag_info);
	return (len_count);
}

int ft_printf_inner(va_list ap, const char *buffer)
{
	int i;
	int len_count;
	t_flag flag_info;

	i = 0;
	len_count = 0;
	while (TRUE)
	{
		flag_info = flag_start();
		if (buffer[i] == '\0')
			break;
		else if (buffer[i] == '%' && buffer[i] != '\0')
		{
			i = get_flag_info(buffer, ++i, &flag_info, ap);
			if (is_valid_type(buffer[i]))
				len_count += (case_divide(buffer[i], ap, flag_info));
			else if (buffer[i])
				len_count += (ft_putchar(buffer[i]));
		}
		else if (buffer[i] != '%')
			len_count += ft_putchar(buffer[i]);
		i++;
	}
	return (len_count);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int len_count;
	const char *buffer;

	len_count = 0;
	buffer = ft_strdup(format);
	va_start(ap, format);
	len_count += ft_printf_inner(ap, buffer);
	va_end(ap);
	free((char *)buffer);
	return (len_count);
}
