NAME = RPN

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC =  main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = RPN.hpp

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
