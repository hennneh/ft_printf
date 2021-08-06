SOURCES = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c  ft_memchr.c \
				ft_isascii.c ft_isprint.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c \
				ft_memcmp.c ft_strchr.c ft_strncmp.c ft_strrchr.c\
				ft_strnstr.c ft_atoi.c ft_strlcat.c ft_strlcpy.c ft_calloc.c \
				ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c \
				ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_uitoa.c

SOURCES_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstadd_back.c

INCLUDES = ./
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_B = $(SOURCES_B:.c=.o)

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(SOURCES)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SOURCES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus: $(NAME)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SOURCES_B)
	ar rc $(NAME) $(OBJECTS_B)
	ranlib $(NAME)
	
clean:
	rm -rf $(OBJECTS) a.out

fclean: clean
	rm -rf $(NAME)

cleanb:
	rm -rf $(OBJECTS)
	rm -rf $(OBJECTS_B) a.out

fcleanb: cleanb
	rm -rf $(NAME)

re: fclean all