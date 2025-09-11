NAME = PhoneBook

C++ = c++

CFLAGS = -Wall -std=c++98

SRC = Contact.cpp main.cpp Phonebook.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Phonebook.hpp Contact.hpp

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