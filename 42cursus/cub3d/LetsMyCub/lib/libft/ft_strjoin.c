/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groom <groom@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:43:23 by groom             #+#    #+#             */
/*   Updated: 2020/07/12 15:25:35 by groom            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		str_len;
	size_t		pr_pos;
	size_t		sf_pos;
	char		*sum_str;

	if (!s1 || !s2)
		return (NULL);
	pr_pos = -1;
	sf_pos = -1;
	str_len = ft_strlen(s1) + ft_strlen(s2);
	sum_str = (char*)malloc(str_len + 1);
	if (!sum_str)
		return (sum_str);
	while (++pr_pos < ft_strlen(s1))
		sum_str[pr_pos] = s1[pr_pos];
	while (++sf_pos < ft_strlen(s2))
		sum_str[pr_pos + sf_pos] = s2[sf_pos];
	sum_str[str_len] = '\0';
	return (sum_str);
}
