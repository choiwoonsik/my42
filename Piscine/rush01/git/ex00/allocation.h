/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swpark <seongwop@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:55:58 by swpark            #+#    #+#             */
/*   Updated: 2020/06/06 23:37:44 by swpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_H
# define ALLOCATION_H
# include <stdlib.h>

int		*ft_init_num_sight(char *argv[], int *num_sight);
int		**ft_init_map(int **map, int map_size);
int		**ft_del_map(int **map);
int		ft_parse_input(char *argv[], int *num_sight);

#endif
