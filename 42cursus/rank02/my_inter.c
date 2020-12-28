/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:13:47 by woonsik           #+#    #+#             */
/*   Updated: 2020/12/22 16:21:51 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j, k;
    char c;
    int used[256];

    if (argc == 3)
    {
        i = 0;
        while (i < 256)
        {
            used[i] = 0;
            i++;
        }
        j = 0;
        while(argv[1][j])
        {
            c = argv[1][j];
            k = 0;
            while (argv[2][k])
            {
                if (c == argv[2][k] && used[argv[2][k]] == 0)
                {
                    used[(unsigned int) argv[1][j]] = 1;
                    write(1, &argv[2][k], 1);
                }
                k++;
            }
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}