# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchoi <wchoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 20:08:11 by wchoi             #+#    #+#              #
#    Updated: 2020/11/29 17:38:59 by wchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS_NAME = main.c \
			init.c\
			casting_init.c\
			casting_wall.c\
			casting_floor.c\
			cub3d.c\
			map_check.c\
			key_control.c\
			textures.c\
			gnl.c\
			parsing_info.c\
			parsing_info2.c\
			parsing_info3.c\
			utils.c\
			utils2.c\
			sprite_init.c\
			casting_sprite.c\
			calc_sprite.c\
			screen_shot.c\
			free_all.c\
			all_info_check.c\

SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

SCREENSHOT = screenshot.bmp

HEADER	= -I./header

CFLAG	= -Wall -Wextra -Werror# -g3 -fsanitize=address

LIBFT	= libft.a

LIBMLX	= libmlx.a

MLX	= -framework OpenGL -framework Appkit

LIBS	= -L./lib/libft -lft -L./lib/mlx -lmlx

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(LIBMLX)
	gcc -o $(NAME) $(OBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

bonus	: $(BOBJ) $(LIBFT) $(LIBMLX)
	gcc -o $(NAME) $(BOBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

$(LIBFT):
	$(MAKE) -C lib/libft

$(LIBMLX):
	$(MAKE) -C lib/mlx

clean	:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/mlx clean
	rm -rf $(OBJ_PATH) $(BOBJ_PATH) $(SCREENSHOT)

fclean	: clean
	$(MAKE) -C lib/libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re
