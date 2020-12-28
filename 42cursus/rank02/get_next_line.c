/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:31:07 by woonsik           #+#    #+#             */
/*   Updated: 2020/12/28 19:07:30 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *remains, char *buffer)
{
	char	 		*array;
	unsigned int	len;
	int 			i;
	int 			j;

	if (!remains && !buffer)
		return (NULL);
	len = ft_strlen(remains) + ft_strlen(buffer);
	array = malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	if (remains)
	{
		while (remains[j])
		{
			array[i] = remains[j];
			i++;
			j++;
		}
	}
	j = 0;
	while (buffer[j])
	{
		array[i] = buffer[j];
		i++;
		j++;
	}
	array[len] = '\0';
	free((void *)remains);
	return (array);
}

char	*push_line(char *remains)
{
	int		i;
	char	*array;

	i = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	array = malloc(sizeof(char) * (i + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		array[i] = remains[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char    *cut_next_line(char *remains)
{
    int i;
    int j;
    char *array;

    i = 0;
    j = 0;
    while (remains[i] && remains[i] != '\n')
        i++;
    if (!remains[i])
    {
        free(remains);
        return (NULL);
    }
    if (!(array = malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
        return (NULL);
    i++;
    while (remains[i])
    {
        array[j] = remains[i];
        i++;
        j++;
    }
    array[j] = '\0';
    free(remains);
    return (array);
}

int		get_next_line(char **line)
{
	static char *remains;
	char		buffer[BUFFER_SIZE + 1];
	int			count;
	int			fd;

	count = 1;
	fd = 0;
	if (!line)
		return (-1);
	while (buffer[0] != '\n' && count != 0)
	{
		if ((count = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	*line = push_line(remains);
	remains = cut_next_line(remains);
	return (count == 0 ? 0 : 1);
}