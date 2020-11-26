/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:59:01 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 11:10:41 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			free_line(char *line, int ret)
{
	free(line);
	return (ret);
}

int			is_upper(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (TRUE);
	return (FALSE);
}

int			is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (TRUE);
	return (FALSE);
}

int			is_digit(char c)
{
	if (ft_isdigit(c))
		return (TRUE);
	return (FALSE);
}
