NAME = Interface

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp MateriaSource.hpp IMateriaSource.hpp

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