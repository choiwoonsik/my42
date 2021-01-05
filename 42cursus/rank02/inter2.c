/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:35:07 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/05 10:46:51 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     main(int argc, char *argv[])
{
    if (argc == 3)
    {
        int    word[256];
        int     i;
        int     j;
        char    c;
        
        i = 0;
        while (i < 256)
        {
            word[i] = 0;
            i++;
        }
        i = 0;
        while (argv[1][i])
        {
            c = argv[1][i];
            j = 0;
            while (argv[2][j])
            {
                if (argv[2][j] == c && word[(unsigned int) argv[2][j]] == 0)
                {
                    word[(unsigned int) argv[1][i]] = 1;
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