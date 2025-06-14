NAME = PhoneBook

C++ = c++

CFLAGS = -Wall #-Wextra -Werror

SRC = Contact.cpp main.cpp Phonebook.cpp

OBJ = $(SRC:.cpp=.o)


all:$(NAME)

$(NAME):$(OBJ)
	$(C++) $(CFLAGS) -o $@ $^

%.o: %.c
	$(C++) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re