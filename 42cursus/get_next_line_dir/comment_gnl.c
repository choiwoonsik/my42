/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:47:12 by wchoi             #+#    #+#             */
/*   Updated: 2020/08/02 16:21:04 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
1. fd가 가르키는곳으로부터 read해서 읽은게 있다면 그 길이만큼 page에 넣는다
2. 계속 넣다가 page[fd]에 개행이있다면 return
3. ret함수 실행해서
3-1. page[fd]가 널이 아니고 page[fd]에 개행이있다면 다시 다음 문장을 동적할당해서 *line에 넣고 뒤부분을 page[fd]에 넣고 반환해서 끝낸다
3-2. page[fd]가 널이 아닌데 개행이 업다면 eof이므로 담고있는걸 전부 *line에 넣고 끝낸다
3-3 아예 내용이없다면 그냥 빈공간 할당해서 *line에 넣고 끝낸다
*/

int		get_last(char *page)
{
	int				i;

	i = 0;
	while (page[i] != '\0')
	{
		if (page[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		make_new_line(char **line, char **page, int fd, int check_last)
{
	// 개행문자가 있는 backup을 개행문자 전과 후로 잘라서
	// \n 전까지는 line 에다가 주고 \n 후는 다시 static 변수 backup에 백업
	int 	n;
	char	*tmp;

	page[fd][check_last] = '\0';
	*line = ft_strdup(page[fd]);
	n = ft_strlen(page[fd] + check_last + 1);
	if (n == 0)
	{
		free(page[fd]);
		page[fd] = NULL;
		return (1);
	}
	tmp = ft_strdup(page[fd] + check_last + 1);
	free(page[fd]);
	page[fd] = tmp;
	return (1);
}

int		ret_func(int fd, char **page, char **line, int check_last)
{
	int		pos;

	//개행을 만나서 gnl을 탈출한 후 check_last(read반환값)이 음수라면 error
	if (check_last < 0)
		return (-1);
	//page[fd]가 널이 아니고 개행이 존재한다면 새로운 문장을 page에 넣는다
	if (page[fd] && (pos = get_last(page[fd])) >= 0)
		return (make_new_line(line, page, fd, pos));
	//page[fd]가 널이 아닌데 개행이 없다면 전체를 다 읽어서 EOF를 만난 경우이다
	else if(page[fd])
	{
		*line = page[fd];
		page[fd] = NULL;
		return (0);
	}
	//아예 빈 문자열의 텍스트일경우
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*page[4096];
	char			buf[BUFFER_SIZE + 1];
	int				check_last;
	int				pos;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	//fd : 파일 지정 번호 buf : 파일에서 읽은 데이터를 저장할 메모리 공간  len : 읽을 데이터의 크기
	//파일을 읽으면 읽은 size만큼 파일의 다음 읽을 위치가 이동됩니다.
	//읽을 위치가 파일의 끝에 도달하면 더 이상 읽을 데이터가 없으므로 0을 return합니다.
	while ((check_last = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[check_last] = '\0';
		page[fd] = ft_strjoin(page[fd], buf);
		//buf크기만큼 읽어들여서 쌓는데 그곳에 개행문자가 있다면 탈출
		if ((pos = get_last(page[fd])) >= 0)
			return (make_new_line(line, page, fd, pos));
	}
	//읽은 내용을 바탕으로 반환값 지정
	return (ret_func(fd, page, line, check_last));
}
