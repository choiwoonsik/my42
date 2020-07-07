/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 23:16:05 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/15 09:43:29 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		j;
	int		tmp;
	int		ret;

	ret = 1;
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (f(tab[i], tab[j]) > 0)
			{
				ret = 0;
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
