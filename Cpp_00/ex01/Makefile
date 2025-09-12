NAME = PhoneBook

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp main.cpp PhoneBook.cpp PhoneBook_utils.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = PhoneBook.hpp Contact.hpp

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

.PHONY: all clean fclean re