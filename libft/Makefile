NAME = libft.a

RM = rm -f
AR = ar rcs

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
       ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
       arena.c arena_alloc.c ft_lstnew.c ft_lstsize.c \
	   ft_lstdelone.c ft_lstclear.c \
       ft_lstiter.c ft_printf.c ft_putnbr_base.c ft_helpers.c ft_helpers2.c \
	   get_next_line.c get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
