CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

LIBFT = ./libft

SRCS =	ft_printf.c

RM = rm -f

all: $(NAME)

$(NAME):
	make re -C $(LIBFT)
	$(CC) $(FLAGS) $(SRCS)
	ar rc $(NAME)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT)

fclean:
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
