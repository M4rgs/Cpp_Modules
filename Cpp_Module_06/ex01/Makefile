NAME = Serializer

C++ = c++

CFLAGS = -Wall -Wextra -Werror 

SRC = Serializer.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Serializer.hpp

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