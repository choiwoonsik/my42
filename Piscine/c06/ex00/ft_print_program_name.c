/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 22:52:53 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/09 20:24:32 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*name;
	char	m;
	int		n;

	n = argc - 1;
	name = argv[n];
	while (name[n] != '\0')
	{
		write(1, &name[n], 1);
		n++;
	}
	m = '\n';
	write(1, &m, 1);
	return (0);
}
