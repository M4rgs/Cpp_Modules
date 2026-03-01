NAME = Array

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC =  main.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Array.hpp Array.tpp

all:$(NAME)

$(NAME):$(OBJ)
	$(C++) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(C++) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
