SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all
VALGRIND += --trace-children=yes --track-fds=yes --track-origins=yes

NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

leaks:
	$(VALGRIND) ./$(NAME)

.PHONY: all clean fclean re
