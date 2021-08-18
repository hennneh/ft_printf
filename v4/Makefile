NAME=libftprintf.a

LIB=./libft
LIBFT = $(LIB)/libft.a

SRC=char.c \
	hex_l.c \
	hex_u.c \
	int.c \
	ptr.c \
	str.c \
	unsigned.c \
	ft_printf.c 

OBJECTS=$(SRC:.c=.o)

CC=gcc

FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $@
	ar rcs $(NAME) $(OBJECTS)

$(LIBFT):
	make -C $(LIB)

%.o: %.c %.h
	$(CC) $(FLAGS) $< -c -o $@

clean:
	make clean -C $(LIB)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all
