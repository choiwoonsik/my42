/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 20:16:16 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/06 12:35:36 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    char    *s_hello = "dnstlr";

    ft_printf("%.*p\n",  -3, s_hello);
    ft_printf("%.p\n",  s_hello);
    ft_printf("%3.p\n",  s_hello);
    ft_printf("%10.p\n",  s_hello);
    ft_printf("%*.p\n",  -10, s_hello);
    ft_printf("%*.p\n",  10, s_hello);
    printf("======\n");

    printf("%.p\n", s_hello);
    printf("%.p\n",  s_hello);
    printf("%3.p\n",  s_hello);
    printf("%10.p\n",  s_hello);
    printf("%*.p\n",  -10, s_hello);
    printf("%*.p\n",  10, s_hello);
}