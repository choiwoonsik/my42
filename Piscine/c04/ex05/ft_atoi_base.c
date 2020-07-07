/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:02:51 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/06 22:40:20 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int		base_len;
	int		i;
	int		j;
	char	tmp;

	base_len = 0;
	while (*(base + base_len) != '\0')
		base_len++;
	if (base_len == 1 || base_len == 0)
		return (0);
	i = 0;
	while (i < base_len)
	{
		tmp = base[i];
		j = i + 1;
		while (j < base_len)
		{
			if (tmp == base[j] || base[j] == '+' || base[j] == '-'
			|| (base[j] >= 9 && base[j] <= 13) || base[j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_minus_start(char *str, int *start)
{
	int		minus;

	minus = 1;
	while (str[*start] == ' ' || (str[*start] <= 13 && str[*start] >= 9))
		(*start)++;
	while (str[*start] == '+' || str[*start] == '-')
	{
		if (str[*start] == '-')
			minus *= -1;
		(*start)++;
	}
	return (minus);
}

int		make_num(char *str, char *base, int base_len)
{
	int		i;
	int		j;

	i = 0;
	while (*(str + i) != '\0')
	{
		j = 0;
		while (j < base_len)
		{
			if (str[i] == base[j])
				break ;
			j++;
		}
		if (j == base_len)
			return (i);
		i++;
	}
	return (i);
}

void	change_str(char *str, int base_len, char *base, int *return_val)
{
	int		len;
	int		i;
	int		j;
	int		multi;
	int		tmp;

	len = *return_val;
	*return_val = 0;
	i = -1;
	while (i++ < len)
	{
		j = -1;
		multi = 1;
		tmp = 1;
		while (++j < base_len)
		{
			if (str[i] == base[j])
			{
				while (((len - i) - tmp++))
					multi *= base_len;
				multi *= j;
			}
		}
		*return_val += multi;
	}
}

int		ft_atoi_base(char *str, char *base)
{
	int		start;
	int		base_len;
	int		return_val;
	int		minus;
	int		len;

	len = 0;
	start = 0;
	base_len = 0;
	while (*(base + base_len) != '\0')
		base_len++;
	if (!check_base(base))
		return (0);
	minus = check_minus_start(str, &start);
	str += start;
	len = make_num(str, base, base_len);
	if (len == 0)
		return (0);
	return_val = len;
	change_str(str, base_len, base, &return_val);
	return (minus * (return_val - 1));
}
