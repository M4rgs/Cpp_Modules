#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool               isSigned;
        const int          toSignGrade;
        const int          toExecuteGrade;
    public:
        Form();
        Form(const std::string name, int toSignGrade, int toExecuteGrade);
        Form(const Form& other);
        Form &operator=(const Form& other);
        ~Form();

        int getToSignGrade() const;
        int getToExecuteGrade() const;
        bool getIsSigned() const;
        std::string getName() const;

        void beSigned(const Bureaucrat &b);


        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormIsAlreadySigned : public std::exception {
            public :
                const char *what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Form& br);

#endif