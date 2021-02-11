# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonsik <woonsik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 17:07:58 by woonsik           #+#    #+#              #
#    Updated: 2021/02/11 18:19:53 by woonsik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_strlen.s ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s
OBJS		= $(SRCS:.s=.o)

BONUS_SRCS	= ft_list_size_bonus.s ft_list_push_front_bonus.s
BONUS_OBJS	= $(BONUS_SRCS:.s=.o)

NA			= nasm
NA_FLAGS	= -f macho64
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
NAME		= libasm.a
TEST		= test
TEST_BONUS	= test_bonus

%.o: %.s
	$(NA) $(NA_FLAGS) $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean:	clean
	rm -rf $(NAME) $(BONUS) $(TEST) $(TEST_BONUS)

re:	fclean $(NAME)

test:
	$(CC) $(FLAGS) -L. -lasm -o $(TEST) main.c
	./$(TEST) < Makefile

test_bonus:
	$(CC) $(FLAGS) -L. -lasm -o $(TEST_BONUS) main_bonus.c
	./$(TEST_BONUS) < Makefile


.PHONY: clean fclean re test bonus test_bonus