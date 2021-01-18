/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:39:35 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/18 18:01:24 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

/*
추상 구문 트리 만들기
*/

/**
 * root노드에 왼쪽자식 오른쪽 자식 초기화 함수
 *
 * 노드의 타입 초기화 함수
 *
 * 노드의 데이터 초기화 함수
 *
 * 노드 제거 함수
 **/

void		astree_init_binary_branch(t_astree_node *root, t_astree_node *left, t_astree_node *right)
{
	if (root != NULL)
	{
		root->left_child = left;
		root->right_child = right;
		ft_printf("left-child data: %s\n", root->left_child->data);
		ft_printf("right-child data: %s\n", root->right_child->data);
	}
	else
		exit(0);
}

void		astree_set_type(t_astree_node *node, t_nodetype type)
{
	if (node != NULL)
	{
		node->type = type;
	}
}

void		astree_set_data(t_astree_node *node, char *data)
{
	if (node != NULL)
	{
		node->data = data;
	}
}

void		astree_delete(t_astree_node *node)
{
	if (node == NULL)
		return;
		
	else if (node->type)
	{
		free(node->data);
		node->data = NULL;
	}
	
	astree_delete(node->left_child);
	astree_delete(node->right_child);
}