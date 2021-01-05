/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:16:28 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/05 11:40:33 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int ac, char *av[])
{
    if (ac == 3)
    {
        int     i, j;
        int     used[256];
    
        i = 0;
        while (i < 256)
        {
            used[i] = 0;
            i++;
        }
        i = 1;
        while (i < 3)
        {
            j = 0;
            while (av[i][j])
            {
                if (used[(unsigned int) av[i][j]] == 0)
                {
                    used[(unsigned int) av[i][j]] = 1;
                    write(1, &av[i][j], 1);
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
        return (0);
}