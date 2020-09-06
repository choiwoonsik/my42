/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:20:49 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/01 19:26:39 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//				출력 및 길이 체크 부분			//

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