NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRCS =	ft_printf.c \
		print_c.c \
		print_i.c \
		print_p.c \
		print_s.c \
		print_u.c \
		print_x_lo.c \
		print_x_up.c \
		utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
