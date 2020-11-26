/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:19:52 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/26 12:14:51 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			parse_screen_size(t_info *info, char *line)
{
	int		i;
	int		width;
	int		height;

	width = 0;
	height = 0;
	i = pass_upper_space(&line[0], 0);
	i -= 1;
	while (is_digit(line[++i]))
		width = width * 10 + line[i] - '0';
	while (is_space(line[i]))
		i++;
	i -= 1;
	while (is_digit(line[++i]))
		height = height * 10 + line[i] - '0';
	if (width > 1920)
		width = 1920;
	if (height > 1080)
		height = 1080;
	info->config.screen_width = width;
	info->config.screen_height = height;
	return (TRUE);
}

char		*parse_path(char *line)
{
	int		i;
	char	*path;

	i = 0;
	i = pass_upper_space(&line[0], 0);
	path = ft_strdup(line + i);
	return (path);
}

int			parse_color(char *line)
{
	int		color;
	int		colors[3];
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < 3)
		colors[i] = 0;
	i = pass_upper_space(&line[0], 0);
	while (++j < 3 && line[i])
	{
		while (line[i] && ft_isdigit(line[i]))
			colors[j] = colors[j] * 10 + line[i++] - '0';
		if ((!ft_strchr(",", line[i]) && line[i] != '\0') ||
		colors[j] > 255)
			return (FALSE);
		if (ft_strchr(",", line[i]))
			i++;
	}
	color = colors[0] * 256 * 256 + colors[1] * 256 + colors[2];
	return (color);
}

char		*update_map(char *buffer, char *line)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(line, "\n");
	tmp2 = ft_strjoin(buffer, tmp1);
	if (*buffer && buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	free(tmp1);
	return (tmp2);
}
