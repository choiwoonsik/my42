/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 20:41:28 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 13:28:46 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_hexa_len(long long int n)
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

char	*ft_hexa_itoa(unsigned int n)
{
	unsigned int	unbr;
	int				n_len;
	char			*ret;

	n_len = check_hexa_len(n);
	ret = (char*)malloc(n_len + 1);
	if (!ret)
		return (ret);
	unbr = n;
	ret[n_len] = '\0';
	while (1)
	{
		if (unbr % 16 < 10)
			ret[--n_len] = unbr % 16 + '0';
		else if (unbr % 16 >= 10)
			ret[--n_len] = unbr % 16 + 87;
		unbr /= 16;
		if (unbr == 0)
			break ;
	}
	return (ret);
}
