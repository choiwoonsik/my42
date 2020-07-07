CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
AR = ar
ARFLAGS = rcs
RM = rm -f
INC = includes

.PHONY: all clean fclean re

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all