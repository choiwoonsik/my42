/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:47:12 by wchoi             #+#    #+#             */
/*   Updated: 2020/07/30 18:14:08 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		make_new_line(int fd, char **line, char **page)
{
	int 	n;
	int 	i;

	i = 0;
	n = 0;
	while (page[fd][n] != '\0' && page[fd][n] != '\n')
		n++;
	if (page[fd][n] == '\n')
	{
		*line = (char*)malloc(sizeof(n));
		while (i < n)
		{
			line[i] = page[fd][i];
			i++;
		}
		line[i] = '\0';
	}

	else if (page[fd][n] == '\0')
	{
		
	}
}

int		get_next_line(int fd, char **line)
{
	static char		*page[5000];
	char			*tmp_line;
	char			buf[BUFFER_SIZE + 1];
	int				check_last;

	if (fd < 0 && line == NULL)
		return (-1);
	//fd : 파일 지정 번호 buf : 파일에서 읽은 데이터를 저장할 메모리 공간  len : 읽을 데이터의 크기
	//파일을 읽으면 읽은 size만큼 파일의 다음 읽을 위치가 이동됩니다.
	//읽을 위치가 파일의 끝에 도달하면 더 이상 읽을 데이터가 없으므로 0을 return합니다.
	while ((check_last = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[check_last] = '\0';
		if (!page[fd])
			page[fd] = ft_strdup("");
		tmp_line = ft_strjoin(page[fd], buf);
		free(page[fd]);
		page[fd] = NULL;
		page[fd] = tmp_line;
		//buf크기만큼 읽어들여서 쌓는데 그곳에 개행문자가 있다면 탈출
		if (ft_strrchr(page[fd], '\n'))
			break;
	}
	//오류가 발생한경우
	if (check_last < 0)
		return (-1);
	//eof에 도달하였고 page의 끝 혹은 처음이 널문자일경우 종료
	else if (check_last == 0 && (!page[fd]) || !page[fd][0])
		return (0);
	//그외의 경우로 한문장은 다 읽었고 페이지는 더 읽어야 할 경우
	return (make_new_line(fd, line, page));
}