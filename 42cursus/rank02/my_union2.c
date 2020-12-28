/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_union2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:01:35 by woonsik           #+#    #+#             */
/*   Updated: 2020/12/22 16:06:17 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j;
    int used[256];

    if (argc == 3)
    {
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
            while (argv[i][j]) {
                if (used[(unsigned int) argv[i][j]] == 0)
                {
                    write(1, &argv[i][j], 1);
                    used[(unsigned int) argv[i][j]] = 1;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

