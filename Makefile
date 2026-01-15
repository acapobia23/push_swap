CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR = ./includes/libft
LIBFT = -L$(LIBFT_DIR) -lft

NAME = push_swap
BONUS_NAME = checker

SRC = src/main.c \
	  src/setup/data_init.c src/setup/free_error_utils.c src/setup/free_error.c \
	  src/setup/index_setup.c src/setup/stack_init.c src/setup/chunks_setup.c src/push_back.c \
	  src/simple_sort.c src/sorting_algo.c src/sorting_algo_utils.c src/sorting_algo_utils_two.c \
	  src/rules/ft_rules_one.c src/rules/ft_rules_two.c src/rules/ft_rules_three.c src/rules/logic_rules.c \
	  src/rules/logic_rules_utils.c

BONUS_SRC = src_checker/main_checker.c src_checker/checker_setup.c src_checker/free_checker.c \
			src_checker/stack_setup.c src_checker/do_moves.c src_checker/stack_setup_utils.c \
	  		src/rules/ft_rules_one.c src/rules/ft_rules_two.c src/rules/ft_rules_three.c src/rules/logic_rules.c \
	  		src/rules/logic_rules_utils.c src/setup/free_error.c src/setup/free_error_utils.c src/setup/data_init.c
all: $(LIBFT_DIR)/libft.a $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)

bonus: $(LIBFT_DIR)/libft.a $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_SRC)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_SRC) $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re

