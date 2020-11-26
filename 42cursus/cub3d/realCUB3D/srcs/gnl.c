/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:54:57 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 11:33:25 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		*page_join_line(char *page, char *line)
{
	char			*temp;

	temp = ft_strjoin(page, line);
	free(page);
	free(line);
	return (temp);
}

static char		*update_line(char *page, int is_last)
{
	char			*line;
	int				pos;

	line = 0;
	pos = 0;
	if (is_last == 0)
		line = ft_strdup(page);
	else if (is_last > 0)
	{
		while (page[pos] != '\n')
			pos++;
		line = ft_substr(page, 0, pos);
	}
	return (line);
}

static char		*update_page(char *page, int is_last)
{
	char			*tmp;
	int				pos;

	tmp = 0;
	pos = 0;
	if (is_last > 0)
	{
		while (page[pos] != '\n')
			pos++;
		tmp = ft_strdup(page + pos + 1);
	}
	free(page);
	page = NULL;
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	static char		*page[1024] = {0, };
	char			*buffer;
	int				is_last;

	is_last = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (FALSE);
	if (page[fd] == 0)
		page[fd] = ft_strdup("");
	while (ft_strchr(page[fd], '\n') == 0 && is_last > 0)
	{
		if (!(buffer = ft_calloc(1, BUFFER_SIZE + 1)) ||
				(is_last = read(fd, buffer, BUFFER_SIZE)) < 0)
			return (FALSE);
		page[fd] = page_join_line(page[fd], buffer);
	}
	*line = update_line(page[fd], is_last);
	page[fd] = update_page(page[fd], is_last);
	return (is_last > 0 ? TRUE : FALSE);
}
