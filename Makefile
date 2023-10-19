NAME = pipex

CC = clang

CFLAGS = -Werror -Wall -Wextra -fPIE -fsanitize=address

RM = rm -rf

SRCS = 	src/pipex.c\
		src/utils.c\
		libft/libft.a\

SRCS_BONUS = 	src_bonus/pipex_bonus.c\
				src_bonus/utils_bonus.c\
				libft/libft.a\

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -fPIE -o $(NAME)