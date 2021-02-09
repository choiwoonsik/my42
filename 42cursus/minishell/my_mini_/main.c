/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:07:49 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/21 21:51:32 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "srcs/ft_printf.h"
#include "srcs/gnl/get_next_line.h"
#include "srcs/libft/libft.h"
#include "astree.h"


int main(int argc, char *argv[])
{
		t_list *token_list;

	token_list = NULL;
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("<")));
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("a")));
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("<")));
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("b")));
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("<")));
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("c")));
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("echo")));
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("hello")));
	ft_lstadd_back(&token_list, ft_lstnew(create_new_token("world")));

	t_list *head;

	head = token_list;
	parse(head, NULL);
}