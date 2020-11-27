/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:43:57 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/27 16:55:51 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			mini_loop(t_info *info)
{
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, KEY_PRESS, 0, &key_control, info);
	mlx_hook(info->win, KEY_EXIT, 0, &exit_game, info);
	mlx_loop(info->mlx);
	return (0);
}

int			error_message(t_info *info, int exit_code, char *error_message)
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
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		return (SAVE);
	return (TRUE);
}

int			main(int argc, char **argv)
{
	t_info	info;

	if (!valid_argument(argc, argv))
		return (error_message(&info, FALSE, "argument error"));
	mini_value_init(&info);
	mini_config_init(&info);
	if (!parse_info(&info, argv[1]))
		return (error_message(&info, FALSE, "parse error"));
	mini_screen_init(&info);
	mini_init(&info, &info.config);
	if (!(load_texture(&info)))
		return (error_message(&info, FALSE, "load error"));
	if (!(is_possible_map(&info, &info.config)))
		return (error_message(&info, FALSE, "map error"));
	if (!(all_info_check(&info)))
		return (error_message(&info, FALSE, "info error"));
	if (valid_argument(argc, argv) == SAVE)
		return (screenshot(&info));
	mini_loop(&info);
	return (0);
}
