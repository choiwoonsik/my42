/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:41:10 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/05 11:45:05 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int ac, char *av[])
{
    if (ac == 3)
    {
        int     i, j;
        char    c;
        int     used[256];
    
        i = 0;
        while (i < 256)
        {
            used[i] = 0;
            i++;
        }
        i = 0;
        while (av[1][i])
        {
            c = av[1][i];
            j = 0;
            while (av[2][j])
            {
                if (used[(unsigned int) av[2][j]] == 0 && av[2][j] == c)
                {
                    used[(unsigned int) av[2][j]] = 1;
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