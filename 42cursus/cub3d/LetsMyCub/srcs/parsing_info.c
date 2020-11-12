/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:04:14 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 18:54:42 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			g_fd;
int			g_ret;

int			isCubFile(char *path)
{
	int		i;
	int		len;
	int		check;

	i = -1;
	len = ft_strlen(path);
	check = 1;
	if (len > 4)
		check = ft_strncmp(path + len - 4, ".cub", 4);
	if (check == 0)
		return (TRUE);
	return (FALSE);
}

int			parse_info(t_info *info, char *path)
{
	int		type;
	char	*line;

	if (!isCubFile(path))
		return (FALSE);
	if ((g_fd = open(path, O_RDONLY)) < 0)
		return (FALSE);
	g_ret = 1;
	while (g_ret = get_next_line(g_fd, &line)) > 0)
	{
		
	}
}