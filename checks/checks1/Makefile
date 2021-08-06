CC = gcc
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -c

OBJECTS = ft*.o
LIB_PATH = ./libft
INCLUDES = ./includes

SOURCES = \
	./srcs/ft_printf.c \
	./srcs/ft_printf_utils.c \
	./srcs/ft_printf_specifiers.c \
	./srcs/ft_printf_specifiers_2.c \
	./srcs/ft_print_char.c \
	./srcs/ft_print_string.c \
	./srcs/ft_print_decimal.c \
	./srcs/ft_print_pointer.c \
	./srcs/ft_print_hex.c

all:$(NAME)

$(NAME):
	make re -C $(LIB_PATH)
	$(CC) $(FLAGS) $(SOURCES) -I$(INCLUDES)
	ar rc $(NAME) $(OBJECTS) $(LIB_PATH)/*.o
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all

.PHONY:        all clean fclean re