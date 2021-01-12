/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:08:50 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/12 12:14:22 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int ac, char *av[])
{
    if (ac == 3)
    {
        int i, j;
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
            j = 0;
            while (av[2][j])
            {
                if (c == av[2][j] && used[(unsigned int) c] == 0)
                {
                    used[(unsigned int) c] = 1;
                    write(1, &c, 1);
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}