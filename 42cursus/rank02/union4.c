/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:17:22 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/12 12:19:01 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int ac, char *av[])
{
    if (ac == 3)
    {
        int i;
        int used[256];

        i = 0;
        while (i < 256)
        {
            used[i] = 0;
            i++;
        }

        i = 0;
        while (av[1][i])
        {
            char c = av[1][i];
            if (used[(unsigned int) c] == 0) 
            {
                used[(unsigned int)c] = 1;
                write(1, &c, 1);
            }
            i++;
        }

        i = 0;
        while (av[2][i])
        {
            char c = av[2][i];
            if (used[(unsigned int) c] == 0)
            {
                write(1, &c, 1);
                used[(unsigned int)c] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}