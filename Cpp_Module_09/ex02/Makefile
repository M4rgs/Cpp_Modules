NAME = PmergeMe

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC =  main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = PmergeMe.hpp

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
