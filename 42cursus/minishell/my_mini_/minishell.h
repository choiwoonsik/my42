/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 21:42:09 by cbaek             #+#    #+#             */
/*   Updated: 2021/01/18 21:23:16 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> // TODO: stdio.h 헤더 삭제
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
//
# include "../srcs/libft/libft.h"
# include "../srcs/gnl/get_next_line.h"
# include "../srcs/ft_printf.h"
//
//# include "../libs/gnl/get_next_line.h"
//# include "../libs/libft/libft.h"

/*
** ==========================================================================
**  Constants
** ==========================================================================
*/

# define FALSE		0
# define TRUE		1

# define SPACE		32
# define SEMICOLON	59
# define GREAT		62
# define GREATGREAT	2
# define LESS		60
# define PIPE		124
# define S_QUOTE	39
# define D_QUOTE	34
# define STRING		1
# define BACKSLASH	92
# define BUFF_SIZE	4096 // 버퍼 사이즈 적절한지 체크 필요

/*
** ==========================================================================
**  structs
** ==========================================================================
*/

typedef struct		s_token
{
	char	*data;
	int		type;
}					t_token;

typedef struct		s_scanner_flags
{
	int		s_quote;
	int		d_quote;
}					t_scanner_flags;

typedef struct		s_env
{
	char	*key;
	char	*val;
}					t_env;

typedef struct		s_rplc_env_note
{
	int		idx;
	int		end;
	int		crr;
}					t_rplc_env_note;

/*
** ==========================================================================
**  scanner/set_token_list.c
** ==========================================================================
*/

int					set_token_list(t_list **token_list, char *line);

/*
** ==========================================================================
**  scanner/replace_env.c
** ==========================================================================
*/

char				*replace_env(char *str, t_list *env_list);

/*
** ==========================================================================
**  scanner/gen_token_string.c
** ==========================================================================
*/

int					gen_token_string(t_list **token_list, char *line, \
							int idx_start);

/*
** ==========================================================================
**  scanner/strip_quotes.c
** ==========================================================================
*/

char				*strip_quotes(char **token_data);

/*
** ==========================================================================
**  util.c
** ==========================================================================
*/

void				free_env(void *env);
char				*get_env_val(char *key, t_list *env_list);
t_token				*create_token(char *line, int start, int end, int type);

/*
** ==========================================================================
**  scanner/util_replace_env1.c
** ==========================================================================
*/

void				init_flag(t_scanner_flags **flag);
void				init_env(t_env **env);
void				init_replace_env(t_rplc_env_note **note, \
							char **result, t_env **env, t_scanner_flags **flag);
int					is_valid_env_start(char chr1, char chr2, \
							t_scanner_flags *flag);
int					is_end_of_env_variable(char chr);

/*
** ==========================================================================
**  scanner/util_replace_env2.c
** ==========================================================================
*/

void				set_quotes_status(char *line, int idx, t_scanner_flags \
							**flag);
int					set_env(t_env **env, char *str, int idx, t_list *env_list);
void				free_env_flag_note(t_env *env, t_scanner_flags *flag, \
							t_rplc_env_note *note);

/*
** ==========================================================================
**  envp/envp.c
** ==========================================================================
*/

void				unset_env_one(t_list **env_head, char *key);
void				set_env_one(t_list *list, t_env *env);
void				print_env_list(t_list *env_head);
t_list				*set_env_list(char **envp);

#endif
