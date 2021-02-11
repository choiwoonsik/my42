#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_list
{
	void		*data; 
	struct		s_list *next;
}				t_list;

int         		ft_write(int fd, char *str, int len);
int 		        ft_read(int fd, char *buf, int len);
unsigned int 	    ft_strlen(char *str);
int		            ft_strcmp(void *s, void *s2);
void        		*ft_memcpy(void *dest, void *src, unsigned int size);
char		        *ft_strdup(char *str);
char 		        *ft_strcpy(char *dest, char *src);
void        		ft_list_push_front_bonus(t_list **begin_list, void *data);
int			        ft_list_size_bonus(t_list *begin_list);
#endif