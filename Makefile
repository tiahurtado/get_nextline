CC = gcc
NAME = get_next_line.a
TEST = test_gnl
FLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(NAME) created"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

test: $(OBJ)
	@$(CC) $(FLAGS) main.c $(OBJ) -o $(TEST)
	@echo "$(TEST) created"

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST)
	@echo "$(NAME) and $(TEST) deleted"

re: fclean all

.PHONY: all clean fclean re test