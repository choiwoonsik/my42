/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 10:59:39 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/14 16:51:03 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*re_src;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	re_src = (char*)malloc(sizeof(char) * (i + 1));
	if (!re_src)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		re_src[i] = src[i];
		i++;
	}
	re_src[i] = '\0';
	return (re_src);
}
