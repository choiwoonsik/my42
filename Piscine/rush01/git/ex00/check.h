/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swpark <seongwop@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:01:50 by swpark            #+#    #+#             */
/*   Updated: 2020/06/06 23:39:03 by swpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

int		ft_check_left(int **map, int *num_sight, int map_size, int row);
int		ft_check_right(int **map, int *num_sight, int map_size, int row);
int		ft_check_up(int **map, int *num_sight, int map_size);
int		ft_check_down(int **map, int *num_sight, int map_size);

#endif
