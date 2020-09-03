/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:46:56 by choeunsig         #+#    #+#             */
/*   Updated: 2020/08/12 17:02:45 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    char c = 'a';
    int n = 10;

    printf("1 >%*c<\n", n, c);
    printf("2 >%-*c<\n", n, c);
    printf("3 >%*.c<\n", n, c);
    printf("4 >%-c<\n", c);
    printf("5 >%-.c<\n", c);
    printf("6 >%.c<\n", c);
    printf("7 >%10.4c<\n", c);
    printf("8 >%.4c<\n", c);
    printf("9 >%.c<\n", c);
}