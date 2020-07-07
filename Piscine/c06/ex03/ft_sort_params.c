/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 23:19:56 by wchoi             #+#    #+#             */
/*   Updated: 2020/06/08 20:13:33 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		my_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		diff;

	diff = my_strcmp(s1, s2);
	if (diff == 0)
		return (0);
	else if (diff < 0)
		return (-1);
	else
		return (1);
}

void	print(char **str)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			c = str[i][j];
			write(1, &c, 1);
			j++;
		}
		c = '\n';
		write(1, &c, 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;
	int		cmp;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			cmp = ft_strcmp(argv[i], argv[j]);
			if (cmp > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print(argv);
	return (0);
}
