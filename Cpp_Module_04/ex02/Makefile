NAME = Abstract_Animal

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

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