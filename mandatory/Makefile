# Directories
SRCS_DIR = ./src
OBJS_DIR = ./obj
INCLUDES_DIR = ./includes
LIBFT_DIR = ./libft

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes
LEAKCHECK = -g

# Name of the executable
NAME = push_swap

# Source files grouped by the new directory structure
SRCS_FILES = push_swap/core/main.c \
             push_swap/core/sort_input.c \
             push_swap/core/handle_errors.c \
             push_swap/init/init_stack_a.c \
             push_swap/init/parse_input.c \
             push_swap/utils/helper.c \
             push_swap/utils/stack_utils.c \
             operations/push/push.c \
             operations/radix/radix.c \
             operations/rotate/rotate.c \
             operations/rotate/reverse_rotate.c \
             operations/sort/sort_small.c \
             operations/swap/swap.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

# Header files
INCLUDES_FILES = push_swap.h
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

# Libft library
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Test Arguments (Random sequences)
ARG3   = $(shell shuf -i 1-100 -n 3 | tr '\n' ' ')
ARG5   = $(shell shuf -i 1-100 -n 5 | tr '\n' ' ')
ARG100 = $(shell shuf -i 1-1000 -n 100 | tr '\n' ' ')
ARG500 = $(shell shuf -i 1-2000 -n 500 | tr '\n' ' ')

# Compilation rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(LEAKCHECK) -o $(NAME) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@make -C $(PRINTF_DIR) --no-print-directory

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LEAKCHECK) -c $< -o $@

# Cleanup rules
clean:
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(PRINTF_DIR) clean --no-print-directory
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(PRINTF_DIR) fclean --no-print-directory
	$(RM) $(NAME)

re: fclean all

# --- Benchmarking Tests ---

test3: all
	@ARG=$$(shuf -i 1-100 -n 3 | tr '\n' ' '); \
	echo "Testing 3 numbers: $$ARG"; \
	./$(NAME) $$ARG | wc -l; \
	./$(NAME) $$ARG | ./checker_linux $$ARG

test5: all
	@ARG=$$(shuf -i 1-100 -n 5 | tr '\n' ' '); \
	echo "Testing 5 numbers: $$ARG"; \
	./$(NAME) $$ARG | wc -l; \
	./$(NAME) $$ARG | ./checker_linux $$ARG

test100: all
	@ARG=$$(shuf -i 1-1000 -n 100 | tr '\n' ' '); \
	echo "Testing 100 numbers..."; \
	./$(NAME) $$ARG | wc -l; \
	./$(NAME) $$ARG | ./checker_linux $$ARG

test500: all
	@ARG=$$(shuf -i 1-2000 -n 500 | tr '\n' ' '); \
	echo "Testing 500 numbers..."; \
	./$(NAME) $$ARG | wc -l; \
	./$(NAME) $$ARG | ./checker_linux $$ARG

# --- Error Tests ---

test_errors: all
	@echo "--- RUNNING ERROR TESTS ---"
	@echo "Test 1: Non-numeric input (1 2 a 3)"
	@./$(NAME) 1 2 a 3 2>&1 | cat -e
	@echo "\nTest 2: Duplicate numbers (1 2 2 3)"
	@./$(NAME) 1 2 2 3 2>&1 | cat -e
	@echo "\nTest 3: INT_MAX overflow (1 2147483648 3)"
	@./$(NAME) 1 2147483648 3 2>&1 | cat -e
	@echo "\nTest 4: INT_MIN underflow (1 -2147483649 3)"
	@./$(NAME) 1 -2147483649 3 2>&1 | cat -e
	@echo "\nTest 5: Massive string overflow (1 999999999999999999 3)"
	@./$(NAME) 1 999999999999999999 3 2>&1 | cat -e
	@echo "\nTest 6: Empty string argument (1 \"\" 3)"
	@./$(NAME) 1 "" 3 2>&1 | cat -e
	@echo "\nTest 7: No arguments (Should print absolutely nothing)"
	@./$(NAME) 2>&1 | cat -e
	@echo "\n--- ERROR TESTS COMPLETE ---"
# --- Custom commands ---

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes ./$(NAME) $(ARG100)

.PHONY: all clean fclean re valgrind test3 test5 test100 test500 test_errors
