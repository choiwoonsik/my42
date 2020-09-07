/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 21:05:19 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 15:27:12 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct	flag{
	int		flag_minus;
	int		flag_zero;
	int		flag_dot;
	int		flag_dot_precision;
	int		flag_width;
	int		flag_width_isTrue;
	int		flag_type;
	int		flag_isMinus;
}				flag;

flag	flag_start(void);

flag	treat_str_flag(char *str, flag flag_info);

int		ft_printf(const char *format, ...);

int		get_flag_info(char* buffer, int i, flag *flag_info, va_list ap);

int		case_divide(char type, va_list ap, flag flag_info);

int		case_str_print(char *str, flag flag_info);

int		case_int_print(int integer, flag flag_info);

int		case_char_print(char character, flag flag_info);

int		case_uint_print(unsigned int u_integer, flag flag_info);

int		case_hexa_print(unsigned int hexa, int isBig, flag flag_info);

int		case_pointer_print(unsigned long long pointer, flag flag_info);

int		case_percent_print(flag flag_info);

int		ft_wirte_all(char *out, int precision);

int		isValid_type(char type);

int		isValid_flag(char flag);

char	*case_int_make_str(int integer, int *len_count, flag *flag_info);

char	*precision_of_str(char *str, flag flag_info);

void	calc_precision_int(char *string_int, int precision);

void	get_flag_info_case_dot(char *buffer, int i, flag *flag_info, va_list ap);

void	get_flag_info_case_width(flag *flag_info, va_list ap);

void	get_flag_info_case_left(flag *flag_info);

void	get_flag_info_case_zero(flag *flag_info);

void	get_flag_info_case_digit(char *buffer, int i, flag *flag_info);

#endif