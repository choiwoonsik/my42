/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 20:17:19 by choeunsig         #+#    #+#             */
/*   Updated: 2020/08/19 20:24:47 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_u_len(long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_u_itoa(unsigned int n)
{
	unsigned int	unbr;
	int				n_len;
	char			*ret;

	n_len = check_u_len(n);
	ret = (char*)malloc(n_len + 1);
	if (!ret)
		return (ret);
	unbr = n;
	ret[n_len] = '\0';
	while (1)
	{
		ret[--n_len] = unbr % 10 + '0';
		unbr /= 10;
		if (unbr == 0)
			break ;
	}
	return (ret);
}
