/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:09:43 by woonsik           #+#    #+#             */
/*   Updated: 2020/12/28 20:54:46 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
    int     i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        i++;
    }
    return (i);
}

char	*ft_strjoin(char *remains, char *buffer)
{
    int     i;
    int     j;
    char    *str;
    unsigned int     len;

    i = 0;
    if (!remains && !buffer)
        return (NULL);
    len = ft_strlen(remains) + ft_strlen(buffer);
    str = malloc(sizeof(char) * (len  + 1));
    if (remains)
    {
        while (remains[i])
        {
            str[i] = remains[i];
            i++;
        }
    }
    j = 0;
    while (buffer[j])
    {
        str[i] = buffer[j];
        i++;
        j++;
    }
    str[len] = '\0';
    free((void *)remains);
    return (str);
}

char	*push_line(char *remains)
{
    int     i;
    char    *str;

    i = 0;
    while (remains[i] != '\n' && remains[i])
        i++;
    str = malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (remains[i] != '\n' && remains[i])
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

    while (remains[i] && remains[i] != '\n')
        i++;
    if (!remains[i])
    {
        free((void *) remains);
        return (NULL);
    }
    str = malloc(sizeof(char) * (ft_strlen(remains) - i + 1));
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (remains[i])
    {
        str[j] = remains[i];
        i++;
    }
    str[j] = '\0';
    free((void *) remains);
    return (str);
}

int		get_next_line(char **line)
{
    static char     *remains;
    char            buffer[BUFFER_SIZE + 1];
    int             fd;
    int             count;

    count = 1;
    fd = 0;
    if (!line)
        return (-1);
    while (buffer[0] != '\n' && count != 0)
    {
        count = read(fd, buffer, BUFFER_SIZE);
        if (count == -1)
            return (-1);
        buffer[count] = '\0';
        remains = ft_strjoin(remains, buffer);
    }
    *line = push_line(remains);
    remains = cut_next_line(remains);
    return (count == 0 ? 0 : 1);
}