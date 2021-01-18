/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:10:37 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/18 21:02:40 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "astree.h"

t_tock      *curtock = NULL;

// command line

/*
1. job ; command line
2. job ;
3. job
*/

// job

/*
1. command | job
2. command
*/

// command

/*
1. simple_command < simple_command
2. simple_command > sumple_command
3. simple_command
*/

// simple_command

/*
1. pathname token_list
*/

// token_list

/*
1. token token_list
2. empty
*/

t_astree_node		*command_line();
t_astree_node		*command_line1();
t_astree_node		*job();
t_astree_node		*job1();
t_astree_node		*command();
t_astree_node		*command1();
t_astree_node		*simple_command();
t_astree_node		*simple_command1();
t_astree_node		*token_list();
t_astree_node		*token_list1();
t_astree_node		*token_list2();

// is_divisor()

int		is_divisor(int token_type, char**buffer_ptr)
{
	if (curtock == NULL)
		return (0);
	else if (curtock->type == token_type)
	{
		// 토큰 타입 일치
		if (!buffer_ptr)
		{
			*buffer_ptr = malloc(sizeof(char) * (ft_strlen(curtock->data) + 1));
			ft_strlcpy(*buffer_ptr, curtock->data, ft_strlen(curtock->data) + 1);
		}
		curtock = curtock->next;
		return (1);
	}
	else
	{
		curtock = curtock->next;
		return (0);
	}
}

// command line

t_astree_node        *command_line()
{
	t_tock				*save;
	t_astree_node		*node;

	save = curtock;
	
	//
	ft_printf("\n");
	t_tock		*tmp;
	tmp = 		curtock;
	int i = 0;
	while (i < 5)
	{
		ft_printf("%c >> ", tmp->type);
		ft_printf("%s ** ", tmp->data);
		tmp = tmp->next;
		i++;
	}
	//

	if ((node = command_line1()) != NULL)
		return node;

	// curtock = save;
	// if ((node = command_line2()) != NULL)
	// 	return node;

	// curtock = save;
	// if ((node = command_line3()) != NULL)
	// 	return node;

	return NULL;
}

// 1. job ; command line

t_astree_node		*command_line1()
{
	t_astree_node *job_node;
	t_astree_node *cmd_line_node;
	t_astree_node *cmd_line1_parent;

	// job
	if (!(job_node = job()))
		return (NULL);
	// SEQ
	if (!(is_divisor(CHAR_SEMICOLON, NULL))) 
	{
		astree_delete(job_node);
		return (NULL);
	}
	// command_line
	if (!(cmd_line_node = command_line()))
	{
		astree_delete(job_node);
		return (NULL);
	}

	cmd_line1_parent = malloc(sizeof(*cmd_line1_parent));
	astree_set_type(cmd_line1_parent, NODE_SEQ);
	astree_init_binary_branch(cmd_line1_parent, job_node, cmd_line_node);

	return (cmd_line1_parent);
}

// job

t_astree_node *job()
{
	t_tock				*save;
	t_astree_node		*node;

	save = curtock;
	if ((node = job1()) != NULL)
		return (node);
	
	// curtock = save;
	// if ((node = job2()) != NULL)
	// 	return (node);

	return (NULL);
}

// 1. command | job

t_astree_node	*job1()
{
	t_astree_node	*cmd_node;
	t_astree_node	*job_node;
	t_astree_node	*job1_parent;

	if (!(cmd_node = command()))
		return (NULL);

	if (!(is_divisor(CHAR_PIPE, NULL)))
	{
		astree_delete(cmd_node);
		return (NULL);
	}

	if (!(job_node = job()))
	{
		astree_delete(cmd_node);
		return (NULL);
	}

	job1_parent = malloc(sizeof(*job1_parent));
	astree_set_type(job1_parent, NODE_PIPE);
	astree_init_binary_branch(job1_parent, cmd_node, job_node);

	return (job1_parent);
}

// command

t_astree_node	*command()
{
	t_tock				*save;
	t_astree_node		*node;

	save = curtock;
	if ((node = command1()) != NULL)
		return (node);

	// curtock = save;
	// if ((node = command2()) != NULL)
	// 	return (node);

	// curtock = save;
	// if ((node = command3()) != NULL)
	// 	return (node);

	return (NULL);
}

// 1. simple_command < simple_command
// ls < "filename.txt"

t_astree_node	*command1()
{
	t_astree_node		*cmd_right_node;
	t_astree_node		*cmd_parent;

	if (!(cmd_right_node = simple_command()))
		return (NULL);
	
	if (!(is_divisor(CHAR_LESSER, NULL)))
	{
		astree_delete(cmd_right_node);
		return (NULL);
	}

	char	*filename;
	if (!(is_divisor(TOKEN, &filename)))
	{
		free(filename);
		astree_delete(cmd_right_node);
		return (NULL);
	}

	cmd_parent = malloc(sizeof(*cmd_parent));
	astree_set_type(cmd_parent, NODE_REDIRECT_IN);
	astree_set_data(cmd_parent, filename);
	astree_init_binary_branch(cmd_parent, NULL, cmd_right_node);

	return (cmd_parent);
}

// simple_command

t_astree_node	*simple_command()
{
	t_tock				*save;

	save = curtock;
	return simple_command1();
}

/*
1. pathname token_list
*/

t_astree_node	*simple_command1()
{
	t_astree_node		*token_list_node;
	t_astree_node		*sim_cmd_parent;
	char				*path_name;

	if(!(is_divisor(TOKEN, &path_name)))
		return (NULL);

	// toekn_list의 반환값은 NULL이 올수 있으므로 널 체크 x
	token_list_node = token_list();

	sim_cmd_parent = malloc(sizeof(*sim_cmd_parent));
	astree_set_type(sim_cmd_parent, NODE_CMDPATH);
	astree_set_data(sim_cmd_parent, path_name);
	astree_init_binary_branch(sim_cmd_parent, NULL, token_list_node);

	return (sim_cmd_parent);
}

// token_list

t_astree_node	*token_list()
{
	t_tock				*save;
	t_astree_node		*node;

	save = curtock;
	if (!(node = token_list1()))
		return (NULL);
	
	curtock = save;
	if (!(node = token_list2()))
		return (NULL);

	return (NULL);
}

//1. token token_list

t_astree_node	*token_list1()
{
	t_astree_node		*token_list_node;
	t_astree_node		*token_parent;

	// token
	char	*arg;
	if (!(is_divisor(TOKEN, &arg)))
	{
		return (NULL);
	}

	// toekn_list의 반환값은 NULL이 올수 있으므로 널 체크 x
	token_list_node = token_list();

	token_parent = malloc(sizeof(*token_parent));
	astree_set_type(token_parent, TOKEN);
	astree_set_data(token_parent, arg);
	astree_init_binary_branch(token_parent, NULL, token_list_node);

	return (token_parent);
}

//2. empty

t_astree_node	*token_list2()
{
	return NULL;
}


void        parse(t_tock *lexer, t_astree_node** syntax_tree, int len)
{
	curtock = lexer;
	int i = 0;
	while (i < len)
	{
		ft_printf("%c > ", lexer->type);
		ft_printf("%s = ", lexer->data);
		lexer = lexer->next;
		i++;
	}
	*syntax_tree = command_line();
}