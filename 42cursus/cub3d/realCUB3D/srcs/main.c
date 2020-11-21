/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:43:57 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/20 12:34:25 by wchoi            ###   ########.fr       */
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
	if (!(isPossible_map(&info, &info.config)))
		return (ERROR_MESSAGE(&info, FALSE, "map error"));
	
	mini_screen_init(&info);
	mini_init(&info, &info.config);
	f_free(&info);
	return (0);
}