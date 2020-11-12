/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:18:24 by groom             #+#    #+#             */
/*   Updated: 2020/07/10 18:55:43 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_len(long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	unbr;
	int				n_len;
	char			*ret;

	n_len = check_len(n);
	ret = (char*)malloc(n_len + 1);
	if (!ret)
		return (ret);
	if (n < 0)
	{
		ret[0] = '-';
		unbr = n * -1;
	}
	else
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
