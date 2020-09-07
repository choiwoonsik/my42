/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 21:05:19 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 19:09:28 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_flag
{
	int		flag_minus;
	int		flag_zero;
	int		flag_dot;
	int		flag_dot_precision;
	int		flag_width;
	int		flag_width_istrue;
	int		flag_type;
	int		flag_isminus;
}				t_flag;

t_flag			flag_start(void);

t_flag			treat_str_flag(char *str, t_flag flag_info);

int				ft_printf(const char *format, ...);

int				get_flag_info(const char *buffer,
				int i, t_flag *flag_info, va_list ap);

int				case_divide(char type, va_list ap, t_flag flag_info);

int				case_str_print(char *str, t_flag flag_info);

int				case_int_print(int integer, t_flag flag_info);

int				case_char_print(char character, t_flag flag_info);

int				case_uint_print(unsigned int u_integer, t_flag flag_info);

int				case_hexa_print(unsigned int hexa,
				int is_big, t_flag flag_info);

int				case_pointer_print(unsigned long long pointer,
				t_flag flag_info);

int				case_percent_print(t_flag flag_info);

int				ft_wirte_all(char *out, int precision);

int				is_valid_type(char type);

int				is_valid_flag(char flag);

char			*case_int_make_str(int integer,
				int *len_count, t_flag *flag_info);

char			*precision_of_str(char *str, t_flag flag_info);

void			calc_precision_int(char *string_int, int precision);

void			get_flag_info_case_dot(const char *buffer,
				int i, t_flag *flag_info, va_list ap);

void			get_flag_info_case_width(t_flag *flag_info, va_list ap);

void			get_flag_info_case_left(t_flag *flag_info);

void			get_flag_info_case_zero(t_flag *flag_info);

void			get_flag_info_case_digit(const char *buffer,
				int i, t_flag *flag_info);

#endif
