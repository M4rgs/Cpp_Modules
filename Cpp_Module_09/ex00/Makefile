NAME = btc

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98  -fsanitize=address -g3

SRC =  main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = BitcoinExchange.hpp

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
