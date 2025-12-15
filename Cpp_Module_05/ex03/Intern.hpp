#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class Intern
{
    public :
        Intern();
        ~Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        
        AForm   *makeForm(std::string formName, std::string targetName);

        class FormNotFoundExeption : public std::exception
        {
            public :
                const char *what() const throw();
        };
};
#endif