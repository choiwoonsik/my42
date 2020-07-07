/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skweon <skweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 02:12:54 by skweon            #+#    #+#             */
/*   Updated: 2020/06/18 03:42:11 by skweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# define MAX_BUFF 1024

typedef struct	s_answer
{
	int	row;
	int	col;
	int size;
}				t_max;

typedef struct	s_map_info
{
	int		line_num;
	char	blank;
	char	obs;
	char	mark;
	char	**map;
}				t_info;

void			free_map_info(t_info *map_info);
void			free_note(int **note, int line_num);
void			mark_largest_square(t_info *info, t_max *ans);
void			print_max(t_info *info);
void			free_strs(char **strs, int size);
int				**prepare_note(t_info *info, int len);
int				get_line_num(char *file_name);
int				get_next_line_length(int fd);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				get_value(int **note, t_info *info, int r, int c);
char			*get_next_line(int fd, int length);
char			**read_lines(int fd1, int fd2, int line_num, char **result);
char			**read_file(char *file_name);
char			*ft_strdup_and_strcat(char *str, char *src, int size);
char			**ft_split(char *str, char *charset);
char			**get_map(char **lines);
char			check_len(char **map, int line_num);
char			check_chars(t_info *info);
char			check_only_chars(t_info *info);
char			is_map_char(t_info *info, char c);
char			is_valid_map(t_info *info);
char			**read_from_stdin(int size);

t_max			*find_answer_point(int **note, t_info *info, int len);
t_max			*find_largest_square(t_info *info);
t_info			*read_map_info_from_stdin(char *void_param);
t_info			*read_map(char *file_name);
t_info			*parse_map_info(char *info);

#endif
