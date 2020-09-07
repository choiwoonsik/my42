/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 20:16:16 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/07 12:59:46 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	int		len = 0;

	a = 8;
	// len = ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);

	len = ft_printf("%*p", a, (void *)209590960);
	printf("<\n");
	printf("len> %d\n", len);

	// len = ft_printf("%*x", a, 209590960);
	// printf("<\n");
	// printf("len> %d\n", len);

	len = ft_printf("%*p", a, (void *)207038912);
	printf("<\n");
	printf("len> %d\n", len);

	// len = ft_printf("%*x", a, 207038912);
	// printf("<\n");
	// len = printf("len> %d\n", len);

	// len = ft_printf("%*p", a, (void *)1);
	// printf("<\n");
	// printf("len> %d\n", len);

	// len = ft_printf("%*x", a, 1);
	// printf("<\n");
	// printf("len> %d\n", len);

	// len = ft_printf("%*p", a, NULL);
	// printf("<\n");
	// printf("len> %d\n", len);
	
	// len = ft_printf("%*x", a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);
	
	// len = ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);

	// a = 9;
	// len = ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);
	// len = ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);

	
	printf("======\n");
	
	// a = 8;
	// len = printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);

	len = printf("%*p", a, (void *)209590960);
	printf("<\n");
	printf("len> %d\n", len);

	// len = printf("%*x", a, 209590960);
	// printf("<\n");
	// printf("len> %d\n", len);

	len = printf("%*p", a, (void *)207038912);
	printf("<\n");
	printf("len> %d\n", len);

	// len = printf("%*x", a, 207038912);
	// printf("<\n");
	// printf("len> %d\n", len);

	// len = printf("%*p", a, (void *)1);
	// printf("<\n");
	// printf("len> %d\n", len);

	// len = printf("%*x", a, 1);
	// printf("<\n");
	// printf("len> %d\n", len);

	// len = printf("%*p", a, NULL);
	// printf("<\n");
	// printf("len> %d\n", len);
	
	// len = printf("%*x", a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);




	// len = printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);

	// a = 9;
	// len = printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);
	// len = printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// printf("<\n");
	// printf("len> %d\n", len);
}