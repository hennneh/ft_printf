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

# GOTTA REMOVE THIS LATER OR I'LL FAIL THIS PROJECT FOR REAL

test: all
	$(CC) -L. -lftprintf main.c

cleantest: fclean
	$(RM) a.out

# ALSO GOTTA REMOVE THIS AS WELL OR I'LL STILL FAIL FOR REAL

.PHONY: all clean fclean re
