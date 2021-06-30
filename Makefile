CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

PATH_LIBFT = ./libft

SOURCES =	ft_printf.c \
			ft_printf_utils.c
all: $(NAME)

clean:

fclean:

re: fclean all

.PHONY: all clean fclean re
