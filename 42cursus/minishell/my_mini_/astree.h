#include "minishell.h"
# include <stdbool.h>

typedef struct				astree_node
{
	int						type;
	char					*data;
	struct astree_node		*left_child;
	struct astree_node		*right_child;
}							t_astree_node;

typedef enum				nodetype
{
	NODE_PIPE 			= (1 << 0),
	NODE_BCKGRND 		= (1 << 1),
	NODE_SEQ 			= (1 << 2),
	NODE_REDIRECT_IN 	= (1 << 3),
	NODE_REDIRECT_OUT 	= (1 << 4),
	NODE_CMDPATH		= (1 << 5),
	NODE_ARGUMENT		= (1 << 6),

	NODE_DATA 			= (1 << 7),
}							t_nodetype;

typedef struct				tock
{
	char					type;
	char					*data;
	struct tock				*next;
}							t_tock;

enum TokenType{
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
	CHAR_QOUTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_WHITESPACE = ' ',
	CHAR_ESCAPESEQUENCE = '\\',
	CHAR_TAB = '\t',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,

	TOKEN	= -1,
};

void		astree_init_binary_branch(t_astree_node *head, t_astree_node *left, t_astree_node *right);
void		astree_set_type(t_astree_node *node, t_nodetype type);
void		astree_set_data(t_astree_node *node, char *data);
void		astree_delete(t_astree_node *node);
void        parse(t_list *toeknlist, t_astree_node** syntax_tree);