NAME = AForm

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

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