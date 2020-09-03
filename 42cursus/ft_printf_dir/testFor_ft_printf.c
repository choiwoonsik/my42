/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testFor_ft_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choeunsig <choeunsig@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:56:02 by choeunsig         #+#    #+#             */
/*   Updated: 2020/09/03 20:51:22 by choeunsig        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#define PTR_CAST	(void*)(uintptr_t)

int main(void)
{
	int k[5];
	int	len = 0;
	char *tmp = "this is original function";

	//문자열 체크
	/*
	ft_printf("$$test is<<%-20.10s>>test this$$\n", tmp);
	ft_printf("$$test is<<%-5.10s>>test this$$\n", tmp);
	ft_printf("$$test is<<%20.10s>>test this$$\n", tmp);
	ft_printf("$$test is<<%5.10s>>test this$$\n", tmp);
	ft_printf("$$test is<<%.30s>>test this$$\n", tmp);
	ft_printf("$$test is<<%30.30s>>test this$$\n", tmp);
	ft_printf("$$test is<<%-5.s>>test this$$\n", tmp);
	ft_printf("$$test is<<%5.1s>>test this$$\n", tmp);
	ft_printf("$$test is<<%5s>>test this$$\n", tmp);
	tmp = NULL;
	ft_printf("$$test is<<%10s>>test this$$\n", tmp);
	ft_printf("$$test is<<%-10s>>test this$$\n", tmp);
	ft_printf("$$test is<<%-10.2s>>test this$$\n", tmp);
	*/
	
	//숫자체크
	/*
	len = ft_printf("$$test is<<%.20d>>test this$$", 100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%.d>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20d>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%0d>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20d%-20.15s>>test this$$", 2147483647, tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-.20d>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-10.20d>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-.d>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20d>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.5d>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.20d>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-21.20d>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%21.20d>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20.21d>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.21d>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	printf("\n");
	len = ft_printf("%20.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-20.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%21.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-21.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-.20d", -1234567890);
	printf("\tlen : %d\n", len);
	*/

	/*
	ft_printf("$$test is<<%-10c>>test this$$\n", 'c');
	ft_printf("$$test is<<%20u>>test this$$\n", 4294967294);
	ft_printf("$$test is<<%-10.20x>>test this$$\n", 32577);
	ft_printf("$$test is<<%10.20X>>test this$$\n", 32577);
	ft_printf("$$test is<<%20.p>>test this$$\n", k);
	*/

/*
	len = ft_printf("$$test is<<%.20u>>test this$$", 100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%.u>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20u>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%0u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20d%-20.15s>>test this$$", 2147483647, tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-.20u>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-10.20u>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-.u>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.5u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.20u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-21.20u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%21.20u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20.21u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.21u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	printf("\n");
	len = ft_printf("%20.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-20.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%21.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-21.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-.20u", -1234567890);
	printf("\tlen : %d\n", len);
*/
/*
len = ft_printf("$$test is<<%.20x>>test this$$", 100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%.x>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20x>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%0x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20x%-20.15s>>test this$$", 2147483647, tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-.20x>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-10.20x>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-.x>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.5x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.20x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-21.20x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%21.20x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20.21x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20.21x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	printf("\n");
	len = ft_printf("%20.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-20.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%21.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-21.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-.20x", -1234567890);
	printf("\tlen : %d\n", len);
*/
/*
	len = ft_printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%.p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20p%-20.15s>>test this$$", tmp, tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-.p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%-20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	printf("\n");
	len = ft_printf("%20p", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-20p", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("%20p", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-20p", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("%20p", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("%-20p", tmp);
	printf("\tlen : %d\n", len);
	len = ft_printf("%9p", tmp);//11
	printf("\tlen : %d\n", len);
	len = ft_printf("%11p", tmp);//11
	printf("\tlen : %d\n", len);
	len = ft_printf("%2p", tmp);//11
	printf("\tlen : %d\n", len);
	len = ft_printf("%1p", tmp);//11
	printf("\tlen : %d\n", len);
	len = ft_printf("%3p", tmp);//11
	printf("\tlen : %d\n", len);

	ft_printf("--%%p\n");
	ft_printf("pointer display %p\n", PTR_CAST 250);
	ft_printf("null pointer display %p\n", NULL);
    ft_printf("%p\n", PTR_CAST 2445487544);
    ft_printf("%p\n", PTR_CAST 244548);
    ft_printf("%p\n", PTR_CAST 7544);
    ft_printf("%p\n", PTR_CAST 548115554454);
    ft_printf("%p\n", PTR_CAST 0);

*/
	len = ft_printf("-%%\n");
	printf("\tlen : %d\n", len);
	len = ft_printf("%%0p %.*% %.*% %.*% %.*% %.*% %.*% %.*%\n", 0, 0, 0, 0, 0, 0, -0);
	printf("\tlen : %d\n", len);
	len = ft_printf("%%4p %.*% %.*% %.*% %.*% %.*% %.*% %.*%\n", 4, 4, 4, 4, 4, 4, -4);
	printf("\tlen : %d\n", len);
	len = ft_printf("%%10p %.*% %.*% %.*% %.*% %.*% %.*% %.*%\n", 10, 10, 10, 10, 10, 10, -10);
	printf("\tlen : %d\n", len);

	ft_printf("\n$$$$$$$$$$$$ VS $$$$$$$$$$$\n\n");
	ft_printf("\n$$$$$$$$$$$$ VS $$$$$$$$$$$\n\n");

	tmp = "this is original function";

	len = printf("-%%\n");
	printf("\tlen : %d\n", len);
	len = printf("%%0p %-.*% %-.*% %.*% %.*% %.*% %.*% %.*%\n", 0, 0, 0, 0, 0, 0, -0);
	printf("\tlen : %d\n", len);
	len = printf("%%4p %-.*% %-.*% %.*% %.*% %.*% %.*% %.*%\n", 4, 4, 4, 4, 4, 4, -4);
	printf("\tlen : %d\n", len);
	len = printf("%%10p %.*% %.*% %.*% %.*% %.*% %.*% %.*%\n", 10, 10, 10, 10, 10, 10, -10);
	printf("\tlen : %d\n", len);

/*
	printf("--%%p\n");
	printf("pointer display %p\n", PTR_CAST 250);
	printf("null pointer display %p\n", NULL);
    printf("%p\n", PTR_CAST 2445487544);
    printf("%p\n", PTR_CAST 244548);
    printf("%p\n", PTR_CAST 7544);
    printf("%p\n", PTR_CAST 548115554454);
    printf("%p\n", PTR_CAST 0);

	len = printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%.p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20p%-20.15s>>test this$$", tmp, tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-.p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20p>>test this$$", tmp);
	printf("\tlen : %d\n", len);
	printf("\n");
	len = printf("%20p", tmp);
	printf("\tlen : %d\n", len);
	len = printf("%-20p", tmp);
	printf("\tlen : %d\n", len);
	len = printf("%20p", tmp);
	printf("\tlen : %d\n", len);
	len = printf("%-20p", tmp);
	printf("\tlen : %d\n", len);
	len = printf("%20p", tmp);
	printf("\tlen : %d\n", len);
	len = printf("%-20p", tmp);//11
	printf("\tlen : %d\n", len);
	len = printf("%9p", tmp);//11
	printf("\tlen : %d\n", len);
	len = printf("%11p", tmp);//11
	printf("\tlen : %d\n", len);
	len = printf("%2p", tmp);//11
	printf("\tlen : %d\n", len);
	len = printf("%1p", tmp);//11
	printf("\tlen : %d\n", len);
	len = printf("%3p", tmp);//11
	printf("\tlen : %d\n", len);
*/
/*
len = printf("$$test is<<%.20x>>test this$$", 100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%.x>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20x>>test this$$", -2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%0x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20x%-20.15s>>test this$$", 2147483647, tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-.20x>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-10.20x>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-.x>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.5x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.20x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-21.20x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%21.20x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.21x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20.21x>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);

	printf("\n");
	len = printf("%20.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%-20.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%21.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%-21.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%.20x", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%-.20x", -1234567890);
	printf("\tlen : %d\n", len);
*/

/*
	len = printf("$$test is<<%.20u>>test this$$", 100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%.u>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20lu>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%0u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20d%-20.15s>>test this$$", 2147483647, tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-.20u>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-10.20u>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-.u>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.5u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.20u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-21.20u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%21.20u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.21u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20.21u>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);

	printf("\n");
	len = printf("%20.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%-20.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%21.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%-21.20u", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%.20u", -1234567890);
	printf("\tlen : %u\n", len);
	len = printf("%-.20u", -1234567890);
	printf("\tlen : %u\n", len);
*/

	//문자열 체크//
	/*
	len = printf("$$test is<<%-20.10s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%-5.10s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%20.10s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%5.10s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%.30s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%30.30s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%-5.s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%5.1s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%5s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	tmp = NULL;
	len = printf("$$test is<<%10s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%-10s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%-10.2s>>test this$$\n", tmp);
	printf(" len : %d\n", len);
	*/

	//숫자 체크
	/*
	len = printf("$$test is<<%.20d>>test this$$", 100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%.d>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20ld>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%0d>>test this$$", 2147483647);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20d%-20.15s>>test this$$", 2147483647, tmp);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-.20d>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-10.20d>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-.d>>test this$$", -100000000);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20ld>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.5ld>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.20ld>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-21.20ld>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%21.20ld>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%-20.21ld>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);
	len = printf("$$test is<<%20.21ld>>test this$$", -2147483648);
	printf("\tlen : %d\n", len);

	printf("\n");
	len = printf("%20.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%-20.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%21.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%-21.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%.20d", -1234567890);
	printf("\tlen : %d\n", len);
	len = printf("%-.20d", -1234567890);
	printf("\tlen : %d\n", len);
	*/

	/*
	//
	len = printf("$$test is<<%-10c>>test this$$\n", 'c');
	printf(" len : %d\n", len);
	len = printf("$$test is<<%20u>>test this$$\n", (unsigned int)4294967294);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%-10.20x>>test this$$\n", 32577);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%20.10X>>test this$$\n", 32577);
	printf(" len : %d\n", len);
	len = printf("$$test is<<%20.p>>test this$$\n", k);
	printf(" len : %d\n", len);
	printf("%%%%");
	*/
}



// ft_print_str("$$test is<<%s>>test this$$\n", tmp);
	// ft_print_str("$$test is<<%d>>test this$$\n", 100000000);
	// ft_print_str("$$test is<<%d>>test this$$\n", -100000000);
	// ft_print_str("$$test is<<%d>>test this$$\n", -2147483648);
	// ft_print_str("$$test is<<%d>>test this$$\n", 2147483647);
	// ft_print_str("$$test is<<%d%s>>test this$$\n", 2147483647, tmp);
	// ft_print_str("$$test is<<%c>>test this$$\n", 'c');
	// ft_print_str("$$test is<<%u>>test this$$\n", 4294967294);
	// ft_print_str("$$test is<<%x>>test this$$\n", 32577);
	// ft_print_str("$$test is<<%X>>test this$$\n", 32577);
	// ft_print_str("$$test is<<%p>>test this$$\n", k);
	// ft_print_str("%%%%");

	// printf("\n$$$$$$$$$$$$ VS $$$$$$$$$$$\n\n");
	// printf("\n$$$$$$$$$$$$ VS $$$$$$$$$$$\n\n");
	
	// len = printf("$$test is<<%s>>test this$$\n", tmp);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%d>>test this$$\n", 100000000);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%d>>test this$$\n", -100000000);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%ld>>test this$$\n", -2147483648);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%d>>test this$$\n", 2147483647);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%d%s>>test this$$\n", 2147483647, tmp);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%c>>test this$$\n", 'c');
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%u>>test this$$\n", (unsigned int)4294967294);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%x>>test this$$\n", 32577);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%X>>test this$$\n", 32577);
	// printf(" len : %d\n", len);
	// len = printf("$$test is<<%p>>test this$$\n", k);
	// printf(" len : %d\n", len);
	// printf("%%%%");
