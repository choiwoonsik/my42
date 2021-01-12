/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl8.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:26:28 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/11 23:46:12 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL8_H
# define GNL8_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE    1

int     get_next_line(char **line);

#endif