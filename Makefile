NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = push_swap.c \
	algorithm/simple.c \
	algorithm/medium.c \
	algorithm/adaptive.c \
	operations/op_pop_push.c \
	operations/op_reverse_rotate.c \
	operations/op_rotate.c \
	operations/op_swap.c \
	operations/stack_op.c \
	utils/check_flags_valid.c \
	utils/check_numbers_valid.c \
	utils/disorder_calculator.c \
	utils/free_and_error.c \
	utils/ft_lstsize.c \
	utils/create_stack_a.c \
	utils/ft_strcmp.c \
	utils/rank.c \
	benchmark/benchmark.c \
	utils/ft_printf/ft_print_number.c \
	utils/ft_printf/ft_print_string.c \
	utils/ft_printf/ft_printf.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
