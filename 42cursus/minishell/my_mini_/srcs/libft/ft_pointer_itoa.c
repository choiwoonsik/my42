/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:27:54 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 16:20:26 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_pointer_len(unsigned long long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_pointer_itoa(unsigned long long n)
{
	unsigned long long		ullnbr;
	int						n_len;
	char					*ret;

	n_len = check_pointer_len(n);
	ret = (char*)malloc(n_len + 1);
	if (!ret)
		return (ret);
	ullnbr = n;
	ret[n_len] = '\0';
	while (1)
	{
		if (ullnbr % 16 < 10)
			ret[--n_len] = ullnbr % 16 + '0';
		else if (ullnbr % 16 >= 10)
			ret[--n_len] = ullnbr % 16 + 87;
		ullnbr /= 16;
		if (ullnbr == 0)
			break ;
	}
	return (ret);
}
