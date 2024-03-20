NAME = ft_ls
SRCS =	main.c	\
		check.c	\
		flags.c	\
		print.c	\
		utils.c
CC = gcc
LIBFT_PATH = libft
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(FLAGS) -g -o $(NAME) $(SRCS) -L $(LIBFT_PATH) -lft

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all
