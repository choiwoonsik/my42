/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 22:23:31 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/11 22:34:01 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int 	n;

	n = 0;
	if (argc == 2)
	{
		while ((argv[1][n] == ' ' || argv[1][n] == '\t') && argv[1][n] != '\0')
			n++;
		while (argv[1][n] != ' ' && argv[1][n] != '\t' && argv[1][n] != '\0')
		{
			write(1, &argv[1][n], 1);
			n++;
		}
		write(1, "\n", 1);
	}
	else
	{
		write(1, "\n", 1);
	}
	
}