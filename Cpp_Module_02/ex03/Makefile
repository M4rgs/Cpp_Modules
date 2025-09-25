NAME = Fixed

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Fixed.hpp Point.hpp

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