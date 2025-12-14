#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool              isSigned;
    const int         toSignGrade;
    const int         toExecuteGrade;

public:
    AForm();
    AForm(const std::string& name, int toSignGrade, int toExecuteGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string        getName() const;
    bool               getIsSigned() const;
    int                getToSignGrade() const;
    int                getToExecuteGrade() const;

    void beSigned(const Bureaucrat& b);

    void execute(Bureaucrat const & executor) const;

    virtual void executeAction() const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormIsAlreadySigned : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
