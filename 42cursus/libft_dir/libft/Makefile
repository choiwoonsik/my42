CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS = $(BONUS:.c=.o)
AR = ar
ARFLAGS = rcs
RM = rm -f
INC = includes

.PHONY: all clean fclean re bonus

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

bonus : $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJS) $(BONUS_OBJS)

re : fclean all