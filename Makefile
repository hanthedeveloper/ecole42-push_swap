NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = push_swap.c \
	algorithm/medium.c \
	algorithm/simple.c \
	operations/op_pop_push.c \
	operations/op_reverse_rotate.c \
	operations/op_rotate.c \
	operations/op_swap.c \
	operations/stack_op.c \
	utils/disorder_calculator.c \
	utils/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re