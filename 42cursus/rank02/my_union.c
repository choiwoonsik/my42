/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:38:45 by woonsik           #+#    #+#             */
/*   Updated: 2020/12/22 22:37:14 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int used[256];
    int i, j;

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
            while (argv[i][j])
            {
                if (!used[(unsigned int)argv[i][j]])
                {
                    used[(unsigned int)argv[i][j]] = 1;
                    write(1, &argv[i][j], 1);
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}