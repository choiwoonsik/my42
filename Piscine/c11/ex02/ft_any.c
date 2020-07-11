/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 17:08:19 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/15 09:03:05 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_any(char **tab, int (*f)(char*))
{
	int		n;

	n = 0;
	while (tab[n] != '\0')
	{
		if (f(tab[n]) != 0)
			return (1);
		n++;
	}
	return (0);
}