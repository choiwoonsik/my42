/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:57:07 by wchoi             #+#    #+#             */
/*   Updated: 2020/10/07 15:33:46 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>

int     get_next_line(int fd, char **line)
{
    printf("start gnl\n");
    char    buf[10];
    char    *page[4096];
    int     pos;
    int     idx;

    idx = 0;

    pos = read(fd, buf, 3);
    printf("%d\n", pos);
    buf[pos] = '\0';
    printf("%s\n", buf);
    int k = 0;
    while (buf[k] != '\0')
        printf("%c ", buf[k]);

    while ((pos = read(fd, buf, 3)) > 0)
    {
        printf("pos > %d", pos);
        buf[pos] = '\0';
        printf("%s", buf);
        for (int i = 0; i < 1; i++)
            printf("%c ", buf[i]);
    }

    printf("\nend gnl\n");
    return 1;
}

int     main(void)
{
    int     fd;
    int     idx;
    char    *line = 0;
    char    *lineaddress[66];
    int     i;
    int     j;

    j = 0;
    idx = 0;
    fd = open("text", O_RDONLY);

    get_next_line(fd, &line);
    printf("%s\n", line);
    lineaddress[j - 1] = line;
    j++;
}

/*
int		get_next_line(int fd, char **line)
{
	static char		*page[4096];
	char			buf[BUFFER_SIZE + 1];
	int				check_last;
	int				pos;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((check_last = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[check_last] = '\0';
		page[fd] = ft_strjoin(page[fd], buf);
		if ((pos = get_last(page[fd])) >= 0)
			return (make_new_line(line, page, fd, pos));
	}
	return (ret_func(fd, page, line, check_last));
}
*/