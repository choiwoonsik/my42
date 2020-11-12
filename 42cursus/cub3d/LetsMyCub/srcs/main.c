/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:43:57 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 18:41:01 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char **argv)
{
	t_info		info;

	if (!(argc == 2 || (argc == 3 && !ft_strncmp(argv[2], "--save", 6))))
		return (-1);
	mini_value_init(&info);
	mini_screen_init(&info);
	map_init(&info);
	// parsing about map
	parse_info(&info, argv[1]);

	mini_init(&info);
	f_free(&info);
	return (0);
}