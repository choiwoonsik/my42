/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:49:53 by woonsik           #+#    #+#             */
/*   Updated: 2021/06/13 19:44:44 by woonsik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

int main()
{
	char **a;
	char **b;
	char c;
	int i;
	int j;
	char buffer[30];

	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	char buffer_save[30];
	char buff1[891];

	c = 'A';
	if (!(a = malloc(sizeof(char *) * 6)))
		return (0);
	if (!(b = malloc(sizeof(char *) * 6)))
	{
		free(a);
		return (0);
	}
	a[0] = strdup("\0");
	a[1] = strdup("coucou");
	a[2] = strdup("hi");
	a[3] = strdup("gyoza");
	a[4] = strdup("\0");
	b[0] = strdup("\0");
	b[1] = strdup("coucou");
	b[2] = strdup("hi");
	b[3] = strdup("gyoza");
	b[4] = strdup("\0");

	printf("\n\033[0;36m================================\033[0m\n");
	printf("\033[0;36m==========\033[0m \033[1;36mFT_STRCMP\033[0m \033[0;36m===========\033[0m\n");
	printf("\033[0;36m================================\033[0m\n\n");

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("TEST #\033[0;33m%d\033[0m:", i * 5 + j);
			if (ft_strcmp(a[i], b[j]) == (strcmp(a[i], b[j])))
			{
				printf("\033[0;32mTRUE\033[0m\n");
			}
			else
				printf("\033[0;31mFALSE\033[0m\n");

			j++;
		}
		i++;
	}

	printf("\n\033[0;36m================================\033[0m\n");
	printf("\033[0;36m==========\033[0m \033[1;36mFT_STRLEN\033[0m \033[0;36m===========\033[0m\n");
	printf("\033[0;36m================================\033[0m\n\n");
	i = 0;
	while (i < 5)
	{
		printf("TEST #\033[0;33m%d\033[0m:", i);
		if (ft_strlen(a[i]) == (strlen(a[i])))
			printf("\033[0;32mTRUE\033[0m\n");
		else
			printf("\033[0;31mFALSE\033[0m\n");
		i++;
	}

	printf("\n\033[0;36m================================\033[0m\n");
	printf("\033[0;36m==========\033[0m \033[1;36mFT_STRCPY\033[0m \033[0;36m===========\033[0m\n");
	printf("\033[0;36m================================\033[0m\n\n");

	printf("\033[37;2m%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer_save, empty));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));
	printf("\n");
	printf("\033[0;mTEST #\033[0;33m%d\033[0m:", 1);
	if (!strcmp(buffer_save, buffer))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	clear_buffer(buffer, 30);
	clear_buffer(buffer_save, 30);
	printf("\033[37;2m%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer_save, hello_world));
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));
	printf("\n");
	printf("\033[0;mTEST #\033[0;33m%d\033[0m:", 2);
	if (!strcmp(buffer_save, buffer))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	clear_buffer(buffer, 30);
	clear_buffer(buffer_save, 30);
	printf("\033[37;2m%-20s: \"%s\"\n", "char []", alphabet);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer_save, alphabet));
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, alphabet));
	printf("\033[0mTEST #\033[0;33m%d\033[0m:", 3);
	if (!strcmp(buffer_save, buffer))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	clear_buffer(buffer, 30);
	clear_buffer(buffer_save, 30);
	printf("\n");
	printf("\n\033[0;36m================================\033[0m\n");
	printf("\033[0;36m==========\033[0m \033[1;36mFT_WRITE\033[0m \033[0;36m===========\033[0m\n");
	printf("\033[0;36m================================\033[0m\n\n");
	printf("please check by yourself 🤷‍♂️\n\n");
	printf("\n\033[0mTEST #\033[0;33m%d\033[0m:\n", 0);
	while (c < 'Z')
	{
		ft_write(1, &c, 1);
		putchar('\t');
		putchar('-');
		putchar('\t');
		putchar(c);
		printf("\n\033[37;1mTEST #\033[0;33m%d\033[0m:\n", c - 'A' + 1);

		c++;
	}
	ft_write(1, &c, 1);
	putchar('\t');
	putchar('-');
	putchar('\t');
	putchar(c);
	c = '\0';

	printf("\n\n\033[37;1mTEST #\033[0;33m%d\033[0m:", 26);
	printf("\n\033[1;37mTESTING VOID CHAR\033[0m\n");
	ft_write(1, &c, 1);
	putchar('\t');
	putchar('-');
	putchar('\t');
	putchar(c);
	printf("\n\n\033[37;1mTEST #\033[0;33m%d\033[0m:", 27);
	printf("\n\033[1;37mTESTING STRINGS\033[0m\n");
	ft_write(1, alphabet, 26);

	printf("\n\033[0;36m================================\033[0m\n");
	printf("\033[0;36m==========\033[0m \033[1;36mFT_READ\033[0m \033[0;36m===========\033[0m\n");
	printf("\033[0;36m================================\033[0m\n\n");

	printf("\n\n\033[37;1mTEST #\033[0;33m%d\033[0m:\n", 0);
	printf("\033[1;37mPlease check this is the 42-header for \033[1;32mmain.c\033[0m\n");
	int fd;
	int ret;
	fd = open("main.c", O_RDONLY);
	ret = read(fd, buff1, 890);
	buff1[ret] = '\0';
	printf("\033[2;37m%s\033[0m", buff1);
	close(fd);

	printf("\n\033[0;36m================================\033[0m\n");
	printf("\033[0;36m==========\033[0m \033[1;36mFT_STRDUP\033[0m \033[0;36m===========\033[0m\n");
	printf("\033[0;36m================================\033[0m\n\n");
	char *save;
	char *save2;
	printf("\033[2;37m%-20s: \"%s\"\n", "char *", hello_world);
	save = strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libc", save);
	save2 = ft_strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	printf("\n\033[0m");
	printf("\033[0;mTEST #\033[0;33m%d\033[0m:", 0);
	if (!strcmp(save, save2))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	free(save);
	save = NULL;
	free(save2);
	save2 = NULL;
	printf("\033[2;37m%-20s: \"%s\"\n", "char *", empty);
	save = strdup(empty);
	printf("%-20s: \"%s\"\n", "libc", save);
	save2 = ft_strdup(empty);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	printf("\033[0;mTEST #\033[0;33m%d\033[0m:", 1);
	if (!strcmp(buffer_save, buffer))
		printf("\033[0;32mTRUE\033[0m\n");
	else
		printf("\033[0;31mFALSE\033[0m\n");
	free(save);
	save = NULL;
	free(save2);
	save2 = NULL;
	printf("\n\033[0m");
}