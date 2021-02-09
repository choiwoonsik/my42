/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:10:37 by woonsik           #+#    #+#             */
/*   Updated: 2021/01/21 21:43:23 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

t_list      *curtock = NULL;

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
1. simple_command redirection_list
2. simple_command
*/

// redirection_list

/*
1. redirection redirection_list
2. empty
*/

// redirection

/*
1. > filename
2. < filename
3. >> filename
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

// term()

int		term(int token_type, char**buffer_ptr)
{
	t_token *		token;

	token = (t_token *)(curtock->content);
	if (curtock == NULL)
		return (0);
	else if (token->type == token_type)
	{
		// 토큰 타입 일치
		if (!buffer_ptr)
		{
			*buffer_ptr = malloc(sizeof(char) * (ft_strlen(token->data) + 1));
			ft_strlcpy(*buffer_ptr, token->data, ft_strlen(token->data) + 1);
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

bool	term_token(t_list **list_ptr, int token_type, char** arg)
{
	// if (*list_ptr == NULL)
	// 	return false;
	while (*list_ptr)
	{
		if (((t_token *)(*list_ptr)->content)->type == token_type)
		{
			if (arg != NULL) {
				*arg = ft_strdup(((t_token *)(*list_ptr)->content)->data);
			}
			return true;
		}
		*list_ptr = (*list_ptr)->next;
	}
	return false;
}

bool	term_redirection(t_list **list_ptr, char **filename, int *set_type)
{
	if (*list_ptr == NULL)
		return false;
	while (*list_ptr)
	{
		int type = ((t_token *)(*list_ptr)->content)->type;
		if (type == GREAT || type == LESS || type == GREATGREAT)
		{
			if (((t_token *)(*list_ptr)->next->content)->type == STRING)
			{
				*set_type = type;
				*list_ptr = (*list_ptr)->next;
				if (filename != NULL) {
					*filename = ft_strdup(((t_token *)(*list_ptr)->content)->data);
				}
				return true;
			}
		}
		*list_ptr = (*list_ptr)->next;
	}
	return false;
}

// command line

t_astree_node        *command_line()
{
	t_token				*save;
	t_astree_node		*node;

	save = curtock;

	if ((node = command_line1()) != NULL)
		return node;

	curtock = save;
	if ((node = command_line2()) != NULL)
		return node;

	curtock = save;
	if ((node = command_line3()) != NULL)
		return node;

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
	if (!(term(CHAR_SEMICOLON, NULL))) 
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

// 2. job ;

t_astree_node		*command_line2()
{
	t_astree_node	*job_node;
	t_astree_node	*cmd_line2_parent;


	// job
	if(!(job_node = job()))
		return (NULL);

	// SEQ
	if (!(term(CHAR_SEMICOLON, NULL)))
	{
		astree_delete(job_node);
		return (NULL);
	}

	cmd_line2_parent = malloc(sizeof(*cmd_line2_parent));
	astree_set_type(cmd_line2_parent, NODE_SEQ);
	astree_init_binary_branch(cmd_line2_parent, job_node, NULL);

	return (cmd_line2_parent);
}

// 3. job

t_astree_node		*command_line3()
{
	return (job());
}
// job()

t_astree_node *job()
{
	t_token				*save;
	t_astree_node		*node;

	save = curtock;
	if ((node = job1()) != NULL)
		return (node);
	
	curtock = save;
	if ((node = job2()) != NULL)
		return (node);

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

	if (!(term(CHAR_PIPE, NULL)))
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

//	2. command

t_astree_node	*job2()
{
	return (command());
}

// command

t_astree_node	*command()
{
	t_token				*save;
	t_astree_node		*node;

	save = curtock;
	if ((node = command1()) != NULL)
		return (node);

	curtock = save;
	if ((node = command2()) != NULL)
		return (node);

	return (NULL);
}


// **************************************** command 부분 ~ redirection START ****************************************


// 1. <simple_command>  <redirection_list>
// cat > a > b < c

t_astree_node	*command1()
{
	t_astree_node		*cmd_left_node;
	t_astree_node		*redir_list_node;
	t_astree_node		*cmd_parent;

	if (!(cmd_left_node = simple_command()))
		return (NULL);

	redir_list_node = redirection_list();

	cmd_parent = malloc(sizeof(*cmd_parent));
	// astree_set_type(cmd_parent, );
	// astree_set_data(cmd_parent, );
	astree_init_binary_branch(cmd_parent, cmd_left_node, redir_list_node);

	return (cmd_parent);
}

t_astree_node	*command2()
{
	return simple_command();
}

// redirection_list

t_astree_node		*redirection_list()
{
	t_token				*save;
	t_astree_node		*node;

	save = curtock;
	if ((node = redirection_list1()) != NULL)
		return (node);

	curtock = save;
	if ((node = redirection_list2()) != NULL)
		return (node);

	return (NULL);
}

/*
리다이렉션 리스트 
1번 - <redirection> <redirection_list>
2번 - <empty>
*/

t_astree_node		*redirection_list1()
{
	t_astree_node		*redirec_right_node;
	t_astree_node		*redirec_parent;

	char *filename;
	char *type;
	if (!(term_redirection(curtock, filename, type)))
		return (NULL);

	redirec_right_node = redirection_list();

	redirec_parent = malloc(sizeof(*redirec_parent));
	astree_set_type(redirec_parent, type);
	astree_set_data(redirec_parent, filename);
	astree_init_binary_branch(redirec_parent, NULL, redirec_right_node);

	return (redirec_parent);
}

t_astree_node		*redirection_list2()
{
	return (NULL);
}

// redirection

/*
1번 : > filename
2번 : < filename
3번 : >> filename
*/

// **************************************** command 부분 ~ redirection END ****************************************


// **************************************** simpple command 부분 ~ token START ****************************************

// simple_command

t_astree_node	*simple_command()
{
	t_token				*save;

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

	if(!(term(TOKEN, &path_name)))
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
	t_token				*save;
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
	if (!term_token(curtock, TOKEN, &arg))
		return (NULL);

	// toekn_list의 반환값은 NULL이 올수 있으므로 널 체크 x
	token_list_node = token_list();

	token_parent = malloc(sizeof(*token_parent));
	astree_set_type(token_parent, NODE_ARGUMENT);
	astree_set_data(token_parent, arg);
	astree_init_binary_branch(token_parent, NULL, token_list_node);

	return (token_parent);
}

//2. empty

t_astree_node	*token_list2()
{
	return (NULL);
}

// **************************************** simpple command 부분 ~ token END ****************************************


void        parse(t_list *toekn_list, t_astree_node** syntax_tree)
{
	curtock = (t_token *)toekn_list;
	*syntax_tree = command_line();
}