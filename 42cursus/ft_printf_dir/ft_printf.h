/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:23:24 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/02 21:35:23 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

#define TRUE 1
#define FALSE 0

typedef struct	flag{
	int		flag_minus;
	int		flag_zero;
	int		flag_dot;
	int		flag_dot_precision;
	int		flag_star;
	int		flag_width;
	int		flag_width_isTrue;
	int		flag_type;
	int		flag_isMinus;
}				flag;

flag	flag_start(void);
int		get_flag_info(char* buffer, int i, flag *flag_info, va_list ap);
int		ft_printf(const char *format, ...);
int		case_divide(char type, va_list ap, flag flag_info);
int		case_str_print(char *str, va_list ap, flag flag_info);
int		case_int_print(int integer, va_list ap, flag flag_info);
int		case_char_print(char character, va_list ap, flag flag_info);
int		case_uint_print(unsigned int u_integer, va_list ap, flag flag_info);
int		case_hexa_print(unsigned int hexa, int isBig, va_list ap, flag flag_info);
int		case_pointer_print(unsigned long long pointer, va_list ap, flag flag_info);
int		case_percent_print(void);
int		ft_wirte_all(char *out, int precision);
int		isValid_type(char type);
int		isValid_flag(char flag);
char	*precision_of_str(char *str, flag flag_info);
void	calc_precision_int(char *string_int, int precision);

flag	treat_str_flag(char *str, flag flag_info);

#endif