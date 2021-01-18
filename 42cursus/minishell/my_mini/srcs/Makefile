LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		all/case_hexa_big_small.c \
		all/case_int.c \
		all/case_int_func.c \
		all/case_percent.c \
		all/case_pointer.c \
		all/case_str.c \
		all/case_uint.c \
		all/case_char.c \
		all/write_all.c \
		all/control_flag.c \
		all/control_flag_case.c \
		
SURPL_O = case_hexa_big_small.o \
		case_int.o \
		case_int_func.o \
		case_percent.o \
		case_pointer.o \
		case_str.o \
		case_uint.o \
		write_all.o \
		control_flag.o \
		control_flag_case.o \
		case_char.o \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a ./$(NAME)
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