/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:16:45 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/03 22:00:34 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		case_char_print(char character)
{
	int		len_count;

	len_count = 0;
	write(1, &character, 1);
	len_count++;
	return (len_count);
}