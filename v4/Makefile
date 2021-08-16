NAME=libftprintf.a

LIB=./libft
LIBFT = $(LIB)/libft.a

SRC=./format_char.c \
	./format_hexa_l.c \
	./format_hexa_u.c \
	./format_int.c \
	./format_ptr.c \
	./format_str.c \
	./format_unsigned.c \
	./ft_printf.c 

OBJECTS=$(SRC:.c=.o)

CC=gcc

FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@cp $(LIBFT) $@
	@ar rcs $(NAME) $(OBJECTS)

$(LIBFT):
	@make -C $(LIB)

%.o: %.c %.h
	@$(CC) $(FLAGS) $< -c -o $@

clean:
	@make clean -C $(LIB)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all

so: $(OBJECTS)
	@$(CC) $(FLAGS) -shared -fpic $(OBJECTS) -o $(NAME:.a=.so)
