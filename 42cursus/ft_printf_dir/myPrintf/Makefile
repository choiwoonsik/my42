LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		all/case_hexa_big_small.c \
		all/case_int.c \
		all/case_percent.c \
		all/case_pointer.c \
		all/case_str.c \
		all/case_uint.c \
		all/case_char.c \
		all/write_all.c \
		all/control_flag.c \
		
SURPL_O = ft_printf.o \
		case_hexa_big_small.o \
		case_int.o \
		case_percent.o \
		case_pointer.o \
		case_str.o \
		case_uint.o \
		write_all.o \
		control_flag.o \
		case_char.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all