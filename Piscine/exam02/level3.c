/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 22:37:53 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/12 10:47:52 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		not_already(char c, int *is_first)
{
	return (is_first[(unsigned)c]);
}

void	set_already(char c, int *is_first)
{
	is_first[(unsigned)c] = 0;
}

void	inter(char *argv)
{
	int		befor;
	int		next;
	char	cmp;
	int		is_first[255];

	befor = 0;
	while (befor < 255)
	{
		is_first[befor] = 1;
		befor++;
	}
	befor = 0;
	while (argv[befor] != '\0')
	{
		cmp = argv[befor];
		next = 0;
		while(argv[next] != '\0')
		{
			if (cmp == argv[next])
			{
				if(not_already(cmp, is_first))
					write(1, &cmp, 1);
				set_already(cmp, is_first);
			}
			next++;
		}
		befor++;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 3)
		inter(argv[1]);
	write(1, "\n", 1);
}
