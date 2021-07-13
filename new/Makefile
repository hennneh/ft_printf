CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

RM = rm -f

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	$(CC) -L. -lftprintf main.c

.PHONY: all clean fclean re
