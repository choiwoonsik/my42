/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_macro.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:26:28 by wchoi             #+#    #+#             */
/*   Updated: 2020/11/12 16:28:20 by wchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MACRO
# define KEY_MACRO

# define TRUE 								1
# define FALSE 								0

# define KEY_PRESS 							2
# define KEY_RELEASE 						3
# define KEY_PRESS_MASK 					(1L<<0)
# define KEY_RELEASE_MASK 					(1L<<1)

# define KEY_A								0
# define KEY_S								1
# define KEY_D								2
# define KEY_W								13

# define KEY_EXIT							17
# define KEY_ESCAPE							53

#endif