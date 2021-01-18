/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:20:49 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 15:16:43 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_wirte_all(char *out, int precision)
{
	int		len_count;

	len_count = 0;
	while (out[len_count] && len_count < precision)
	{
		write(1, &out[len_count++], 1);
	}
	return (len_count);
}
