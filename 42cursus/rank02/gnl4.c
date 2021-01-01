/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:13:54 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/01 19:43:33 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        i++;
    }
    return (i);
}

char    *ft_strjoin(char *remains, char *buffer)
{
    int     i;
    int     j;
    char    *str;
    int     len;

    if (!remains && !buffer)
        return (NULL);
    len = ft_strlen(remains) + ft_strlen(buffer);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    if (remains)
    {
        while (remains[i])
        {
            str[i] = remains[i];
            i++;
        }
    }
    j = 0;
    while(buffer[j])
    {
        str[i] = buffer[j];
        i++;
        j++;
    }
    str[len] = '\0';
    free((void *)remains);
    return (str);
}

char    *put_line(char *remains)
{
    int     i;
    char    *str;

    i = 0;
    while (remains[i] && remains[i] != '\n')
        i++;
    str = malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    while (remains[i] && remains[i] != '\n')
    {
        str[i] = remains[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *cut_next_line(char *remains)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    while (remains[i] && remains[i] != '\n')
        i++;
    if (!remains[i])
    {
        free((void *)remains);
        return (NULL);
    }
    str = malloc(sizeof(char) * (ft_strlen(remains) - i + 1));
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (remains[i] && remains[i] != '\n')
    {
        str[j] = remains[i];
        j++;
        i++;
    }
    str[j] = '\0';
    free((void *)remains);
    return (str);
}

int		get_next_line(char **line)
{
    static char     *remains;
    char            buffer[BUFFER_SIZE + 1];
    int             count;
    int             fd;

    if (!line)
        return (-1);
    count = 1;
    fd = 0;
    while (buffer[0] != '\n' && count != 0)
    {
        count = read(fd, buffer, BUFFER_SIZE);
        if (count == -1)
            return (-1);
        buffer[count] = '\0';
        remains = ft_strjoin(remains, buffer);
    }
    *line = put_line(remains);
    remains = cut_next_line(remains);
    return (count == 0 ? 0 : 1);
}