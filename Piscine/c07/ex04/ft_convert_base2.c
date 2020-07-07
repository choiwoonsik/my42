/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:48:41 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/11 20:49:40 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_base(char *base)
{
	int		i;
	int		j;
	char	tmp;
	int		len;

	len = 0;
	while (base[len] != '\0')
		(len)++;
	if (len == 0 || len == 1 || base[0] == '-' || base[0] == '+')
		return (0);
	i = 0;
	while (i < len)
	{
		tmp = base[i];
		j = i + 1;
		while (j < len)
		{
			if (tmp == base[j] || base[j] == '+' || base[j] == '-'
			|| (base[j] <= 13 && base[j] >= 9) || base[j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (len);
}

char	*check_nbr_start(char *nbr, int *minus)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while ((nbr[i] == ' ' || (nbr[i] <= 13 && nbr[i] >= 9)) && nbr[i] != '\0')
	{
		i++;
	}
	while ((nbr[i] == '+' || nbr[i] == '-') && nbr[i] != '\0')
	{
		if (nbr[i] == '-')
			*minus *= -1;
		i++;
	}
	return (nbr + i);
}

int		check_nbr_len(char *nbr, char *base_from)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (nbr[len] != '\0')
	{
		i = 0;
		while (base_from[i] != '\0')
		{
			if (nbr[len] == base_from[i])
				break ;
			i++;
		}
		if (i == check_base(base_from))
		{
			break ;
		}
		len++;
	}
	return (len);
}

int		change_to_num(char *nbr, char *base_from, int from_len, int nbr_len)
{
	int		nbr_pos;
	int		base_pos;
	int		val;
	int		count;
	int		multi;

	val = 0;
	nbr_pos = -1;
	while (++nbr_pos < nbr_len)
	{
		base_pos = -1;
		count = 1;
		multi = 1;
		while (++base_pos < from_len)
		{
			if (nbr[nbr_pos] == base_from[base_pos])
			{
				while (((nbr_len - nbr_pos) - count++))
					multi *= from_len;
				multi *= base_pos;
			}
		}
		val += multi;
	}
	return (val);
}
