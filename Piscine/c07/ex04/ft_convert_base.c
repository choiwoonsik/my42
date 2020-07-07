/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:58:17 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/14 16:46:29 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);
char	*check_nbr_start(char *nbr, int *minus);
int		check_nbr_len(char *nbr, char *base_from);
int		change_to_num(char *nbr, char *base_from, int from_len, int nbr_len);

int		count_to_base(long int val, long int base_len)
{
	int		count;
	int		minus_spase;

	minus_spase = 0;
	count = 0;
	if (val < 0)
	{
		val *= -1;
		minus_spase = 1;
	}
	while (val / base_len > 0)
	{
		val /= base_len;
		count++;
	}
	return (count + 1 + minus_spase);
}

char	*change_to_base(int nbr, char *base, int base_len)
{
	unsigned int	unbr;
	int				idx;
	char			*ret;

	idx = count_to_base(nbr, base_len);
	ret = (char*)malloc(sizeof(char) * (idx + 1));
	if (ret == 0)
		return (ret);
	if (nbr < 0)
	{
		ret[0] = '-';
		unbr = nbr * -1;
	}
	else
		unbr = nbr;
	ret[idx] = '\0';
	while (1)
	{
		ret[--idx] = base[unbr % base_len];
		unbr /= base_len;
		if (unbr == 0)
			break ;
	}
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_len;
	int		base_to_len;
	int		num;
	char	*ret;
	int		nbr_len;

	num = 1;
	base_from_len = check_base(base_from);
	base_to_len = check_base(base_to);
	if (base_from_len == 0 || base_to_len == 0)
		return (0);
	nbr = check_nbr_start(nbr, &num);
	nbr_len = check_nbr_len(nbr, base_from);
	num *= change_to_num(nbr, base_from, base_from_len, nbr_len);
	ret = change_to_base(num, base_to, base_to_len);
	return (ret);
}
