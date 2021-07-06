CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

LIBFT = ./libft

SRCS =	ft_printf.c \
		ft_printf_utils.c \
		ft_printf_hex.c 

RM = rm -f

all: $(NAME)

$(NAME):
	make re $(LIBFT)
	$(CC) $(FLAGS) $(SRCS)
	ar rc $(NAME)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
