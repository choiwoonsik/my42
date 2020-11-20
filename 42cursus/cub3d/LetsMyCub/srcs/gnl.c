/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:54:57 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/19 13:08:03 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		*page_joinLine(char *page, char *line)
{
	char	*temp;

	temp = ft_strjoin(page, line);
	free(page);
	free(line);
	return (temp);
}

static char		*update_line(char *page, int isLast)
{
	char	*line;
	int		pos;

	line = 0;
	pos = 0;
	if (isLast == 0)
		line = ft_strdup(page);
	else if (isLast > 0)
	{
		while (page[pos] != '\n')
			pos++;
		line = ft_substr(page, 0, pos);
	}
	return (line);
}

static char		*update_page(char *page, int isLast)
{
	char	*tmp;
	int		pos;

	tmp = 0;
	pos = 0;
	if (isLast > 0)
	{
		while (page[pos] != '\n')
			pos++;
		tmp = ft_strdup(page + pos + 1);
	}
	free(page);
	page = NULL;
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	static char		*page[1024] = {0, };
	char			*buffer;
	int				isLast;

	isLast = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (FALSE);
	if (page[fd] == 0)
		page[fd] = ft_strdup("");
	while (ft_strchr(page[fd], '\n') == 0 && isLast > 0)
	{
		if (!(buffer = ft_calloc(1, BUFFER_SIZE + 1)) ||
				(isLast = read(fd, buffer, BUFFER_SIZE)) < 0)
			return (FALSE);
		page[fd] = page_joinLine(page[fd], buffer);
	}
	*line = update_line(page[fd], isLast);
	page[fd] = update_page(page[fd], isLast);
	return (isLast > 0 ? TRUE : FALSE);
}