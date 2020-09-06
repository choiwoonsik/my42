/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 20:16:16 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/06 19:16:42 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int n = 0;
   
    n = ft_printf("%05i", 43);
    printf("len>   %d\n\n", n);

    printf("======\n");

    n = printf("%05i", 43);
    printf("len>   %d\n\n", n);
}

// First line of code: {return test("%7d", -14);}
//    3       expected output : "    -14"
//    4       your output     : "     -14"
//    5       expected (nonprintable as hex) : "    -14"
//    6       actual   (nonprintable as hex) : "     -14"
//    7
//    8 Test 202 (d_width_neg_exactfit) : FAILED.
//    9     First line of code: {return test("%5d", -2562);}
//   10       expected output : "-2562"
//   11       your output     : " -2562"
//   12       expected (nonprintable as hex) : "-2562"
//   13       actual   (nonprintable as hex) : " -2562"
//   14
//   15 Test 206 (d_width_neg_fits_lj) : FAILED.
//   16     First line of code: {return test("%-7d", -14);}
//   17       expected output : "-14    "
//   18       your output     : "-14     "
//   19       expected (nonprintable as hex) : "-14    "
//   20       actual   (nonprintable as hex) : "-14     "
//   21
//   22 Test 209 (d_width_neg_exactfit_lj) : FAILED.
//   23     First line of code: {return test("%-5d", -2562);}
//   24       expected output : "-2562"
//   25       your output     : "-2562 "
//   26       expected (nonprintable as hex) : "-2562"
//   27       actual   (nonprintable as hex) : "-2562 "