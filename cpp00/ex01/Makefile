NAME = phonebook
SRC = Phonebook.cpp Contact.cpp Main.cpp utils.cpp 
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -$(LIBS) -g
LIBS = I../utils/

TESTER = test.out
OBJ_TEST = test.o

all: $(NAME)

%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(TESTER): $(NAME) $(OBJ_TEST)
	$(CC) $(CPPFLAGS) -o $(TESTER) $(OBJ_TEST) $(filter-out Main.o, $(OBJ))

test: $(TESTER)
	./$(TESTER)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
