/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 18:17:21 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/01 10:14:55 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_hex[17] = "0123456789abcdef";

void	put_char(char c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				n;
	int				top;
	int				bot;
	unsigned char	u_char;

	n = 0;
	while (*(str + n) != '\0')
	{
		if (*(str + n) < 32 || *(str + n) > 126)
		{
			u_char = (unsigned char)*(str + n);
			put_char('\\');
			top = u_char / 16;
			bot = u_char % 16;
			put_char(g_hex[top]);
			put_char(g_hex[bot]);
		}
		else
		{
			put_char(*(str + n));
		}
		n++;
	}
}
