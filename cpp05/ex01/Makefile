NAME = form
SRC = Bureaucrat.cpp Form.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -$(LIBS) -g
LIBS = I../../utils/

TESTER = test.out
OBJ_TEST = test.o

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

all: $(NAME)

%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(TESTER): $(NAME) $(OBJ_TEST)
	$(CC) $(CPPFLAGS) -o $(TESTER) $(OBJ_TEST) $(filter-out main.o, $(OBJ))

test: $(TESTER)
	./$(TESTER)

leaks:
	$(VALGRIND) ./$(NAME)

clean:
	$(RM) $(OBJ) $(TESTER) $(OBJ_TEST)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
