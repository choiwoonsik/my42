/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 09:47:40 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/02 18:49:26 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n <= 0)
		return (0);
	n--;
	while (*s1 == *s2 && (*s1 != '\0') && (*s2 != '\0') && n != 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}