/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:17:41 by wchoi             #+#    #+#             */
/*   Updated: 2020/10/07 14:59:23 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		get_last(char *storage_line)
{
	int		n;

	n = 0;
	while (storage_line[n] != '\0')
	{
		if (storage_line[n] == '\n')
			return (n);
		n++;
	}
	return (-1);
}

int		make_next_line(int fd, char **line, int pos, char **storage)
{
	int strLen;
	char *tmp;

	storage[fd][pos] = '\0';
	*line = ft_strdup(storage[fd]);
	strLen = ft_strlen(storage[fd] + pos + 1);
	if (strLen == 0)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (1);
	}
	tmp = ft_strdup(storage[fd] + strLen + 1);
	storage[fd] = tmp;
	free(tmp);
	return (1);
}

int		return_func(int fd, char **storage, char **line, int pos)
{
	if (pos < 0)
		return (-1);
	if (storage[fd] != '\0' && get_last(storage[fd]) >= 0)
		return (make_next_line(fd, line, pos, storage));
	else if (storage[fd] != '\0')
	{
		*line = storage[fd];
		free(storage[fd]);
		storage[fd] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char** line)
{
	static char *storage[4096];
	char		buffer[BUFFER_SIZE+ 1];
	int			line_idx;
	int			pos;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((line_idx = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[line_idx] = '\0';
		//storage += buffer[line_idx];
		storage[fd] = ft_strjoin(storage[fd], buffer);
		if ((pos = (get_last(storage[fd]))) >= 0)
		{
			return (make_next_line(fd, line, pos, storage));
		}
	}
	return (return_func(fd, storage, line, pos));
}

// int main(void) {
// 	int             fd;
// 	int             i;
// 	int             j;
// 	char    		*line = 0;
// 	char			*lineadress[66];

// 	j = 1;
//     if (!(fd = open("alphabet", O_RDONLY)))
//         return (-1);
//    	while ((i = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("|%s\n", line);
// 		lineadress[j - 1] = line;
// 		j++;
// 	}
// 	printf("|%s\n", line);
// 	free(line);
// 	close(fd);
// 	if (i == -1)
// 		printf ("\nError in Fonction - Returned -1\n");
// 	else if (j == 66)
// 		printf("\nRight number of lines\n");
// 	else if (j != 66)
// 		printf("\nNot Good - Wrong Number Of Lines\n");
// 	while (--j > 0)
// 		free(lineadress[j - 1]);

// }