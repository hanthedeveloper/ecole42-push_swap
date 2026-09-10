NAME	=

CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

SRC		=	
OBJ		=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re