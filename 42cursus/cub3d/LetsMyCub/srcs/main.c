/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:43:57 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/18 23:20:12 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ERROR_MESSAGE(t_info *info, int exit_code, char *error_message)
{
	int		i;

	i = 0;
	if (error_message)
		write(1, error_message, ft_strlen(error_message));
	exit(exit_code);
	f_free(info);
	return (exit_code);
}

int			valid_argument(int argc, char **argv)
{
	if (!(argc == 2 || (argc == 3 && !ft_strncmp(argv[2], "--save", 6))))
		return (FALSE);
	return (TRUE);
}

void		printf_map(char **map)
{
	int width = ft_strlen(map[0]);
	printf("width : %d\n", width);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 25; j++)
			printf(" %d", map[i][j] - '0');
		printf("\n");
	}
}

int			main(int argc, char **argv)
{
	t_info		info;

	if (!valid_argument(argc, argv))
		return (ERROR_MESSAGE(&info, FALSE, "argument error"));
	
	mini_value_init(&info);
	mini_config_init(&info);
	
	if (!parse_info(&info, argv[1]))
		return (ERROR_MESSAGE(&info, FALSE, "parse error"));
	if (!(load_texture(&info)))
		return (ERROR_MESSAGE(&info, FALSE, "load error"));

	mini_screen_init(&info);

	printf_map(info.config.worldMap);

	mini_init(&info, &info.config);
	f_free(&info);
	return (0);
}