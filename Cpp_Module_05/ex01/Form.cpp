#include "Form.hpp"

Form::Form() : name("def_Form"), toSignGrade(10), toExecuteGrade(10)
{
    std::cout << "Default constructor called !" << std::endl;
    this->isSigned = false;
}

Form::Form(const std::string name, int toSignGrade, int toExecuteGrade) : name(name), toSignGrade(toSignGrade), toExecuteGrade(toExecuteGrade)
{
    if (toSignGrade < 1 || toExecuteGrade < 1)
        throw(GradeTooHighException());
    if (toSignGrade > 150 || toExecuteGrade > 150)
        throw(GradeTooLowException());
    this->isSigned = false;
    std::cout << "Prametrized constructor called !" << std::endl;
}

std::string Form::getName() const 
{
    return (name);
}

int Form::getToSignGrade() const 
{
    return (toSignGrade);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getToExecuteGrade() const
{
    return (toExecuteGrade);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->getToSignGrade())
        throw(GradeTooLowException());
    if (this->getIsSigned())
        throw(FormIsAlreadySigned());
    this->isSigned = true;
}

Form::~Form()
{
    std::cout << "Destructor called !" << std::endl;
}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), toSignGrade(other.toSignGrade), toExecuteGrade(other.toExecuteGrade)
{
    std::cout << "Copy constructor called !" << std::endl;
}

Form &Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.getIsSigned();
    std::cout << "Copy assigmenet operator called !" << std::endl;
    return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high !\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low !\n");
}
const char *Form::FormIsAlreadySigned::what() const throw()
{
    return ("Form is already signed !\n");
}

std::ostream& operator<<(std::ostream& out, const Form& fr) {
    out << "Form " << fr.getName() << ", Grade to sign : " << fr.getToSignGrade() << ", Grade to execute : " << fr.getToExecuteGrade() << ", is signed : " << (fr.getIsSigned() ? "true":"false") << "\n";
    return out;
}
