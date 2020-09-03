/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:17:48 by choeunsig         #+#    #+#             */
/*   Updated: 2020/08/12 16:55:43 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    printf("%*.*d\n", 1, 50, 5000);
    printf("%*.*d\n", 1, 0, 10);
    unsigned int n = -10;
    printf("%u", n);
    printf("%d", n);

    printf("\ntest for +-\n");
    printf("1 >%1.0d<\n", -10);
    printf("1 >%1.0i<\n", -10);
    printf("1 >%1.0u<\n", n);
    printf("1 >%1.0x<\n", -10);
    printf("test for +-\n");

    printf("1 >%1.0d<\n", 10);
    printf("2 >%2.0d<\n", 10);
    printf("3 >%3.0d<\n", 10);
    printf("4 >%4.0d<\n", 10);
    printf("5 >%0.0d<\n", 10);
    printf("6 >%0.1d<\n", 10);
    printf("7 >%0.2d<\n", 10);
    printf("8 >%0.3d<\n", 10);
    printf("9 >%0.4d<\n", 10);
    printf("A >%0.5d<\n", 10);
    printf("B >%6.5d<\n", 10);
    printf("C >%06.d<\n", 10);
    printf("D >%06.2d<\n", 10);
    printf("E >%-6.2d<\n", 10);
    printf("F >%-6.8d<\n", 10);
    printf("G >%-6.5d<\n", 10);
    printf("H >%-6d<\n", 10);


    printf("I >%13s<\n", "this is str");
    printf("J >%-13s<\n", "this is str");
    printf("K >%*.*s<\n", 20, 10, "test string");

    printf("\n=======\n\n");
    printf("%*.*d\n%*.*X\n", 1, 50, 5000, 1, 0, 10);
}