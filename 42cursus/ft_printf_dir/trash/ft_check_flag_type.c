/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:27:11 by choeunsig         #+#    #+#             */
/*   Updated: 2020/08/15 19:36:18 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_type(char c)
{
	if (c == 'c')
		return (c);
	if (c == 's')
        return (c);
	if (c == 'p')
        return (c);
	if (c == 'd')
        return (c);
	if (c == 'i')
        return (c);
	if (c == 'u')
        return (c);
	if (c == 'x')
        return (c);
	if (c == 'X')
        return (c);
	if (c == '%')
        return (c);
	return 0;
}

int		ft_is_flag(char c)
{
	if (c == '-')
		return (c);
	if (c == '0')
		return (c);
	if (c == '.')
		return (c);
	if (c == '*')
		return (c);
}