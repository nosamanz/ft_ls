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

# Test files
TEST_FILES = test_files

create_test_files:
	@echo "Creating test files..."
	@mkdir test_files
	@cd test_files && mkdir TestFolder1 TestFolder2 && touch a b c x y z A B C x y z 1 2 3
	@cd test_files/TestFolder1 && touch test1.txt test2.txt .hidden_file1 .hidden_file2 .hidden_file3
	@cd test_files/TestFolder2 && touch test3.txt test4.txt .A_hidden_file .b_hidden_file .X_hidden_file .x_hidden_file .abc_hidden_file .xyz_hidden_file
	@echo "Test files created !"

delete_test_files: $(TEST_FILES)
	@echo "Deleting test files..."
	@rm -rf test_files
