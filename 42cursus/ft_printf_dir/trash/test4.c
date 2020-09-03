/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:22:31 by choeunsig         #+#    #+#             */
/*   Updated: 2020/08/27 20:44:29 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    //char c[] = "this is string";
    int num = 10;
    int *c = &num;
    int n = 300;

    printf("1 >%*p<\n", n, c);
    printf("2 >%-*p<\n", n, c);
    printf("3 >%*.*p<\n", n, n, c);
    printf("4 >%-p<\n", c);
    printf("5 >%-.p<\n", c);
    printf("6 >%.p<\n", c);
    printf("7 >%10.4p<\n", c);
    printf("8 >%.4p<\n", c);
    printf("9 >%.1p<\n", c);
    printf("A >%.p<\n", c);
    printf("%*d\n", 50, 999);
    printf("%10.1d\n", n);
    printf("%*.*d\n", 100, 10, 333);
    //폭이 100, 정밀도가 10, 숫자가 333
}