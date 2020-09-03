/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:54:22 by choeunsig         #+#    #+#             */
/*   Updated: 2020/08/15 20:00:19 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_flag_minus(t_flag flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}