/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:13:25 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/02 16:56:52 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    char c[] = "this is string";
    int n = 10;

    printf("1 >%*s<\n", n, c);
    printf("2 >%-*s<\n", n, c);
    printf("3 >%*.s<\n", n, c);
    printf("4 >%-s<\n", c);
    printf("5 >%-.s<\n", c);
    printf("6 >%.s<\n", c);
    printf("7 >%10.4s<\n", c);
    printf("8 >%.4s<\n", c);
    printf("9 >%.1s<\n", c);
    printf("A >%.s<\n", c);
}