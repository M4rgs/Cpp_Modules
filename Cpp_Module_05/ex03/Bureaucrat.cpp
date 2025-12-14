#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("def_bureaucrat"), grade(10)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
    this->grade = grade;
}

std::string Bureaucrat::getName() const 
{
    return (name);
}

int Bureaucrat::getGrade() const 
{
    return (grade);
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw(GradeTooLowException());
    this->grade++;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw(GradeTooHighException());
    this->grade--;
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try 
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << getName() << " couldn’t execute " << form.getName() << " because: " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.getGrade();
    return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high !\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low !\n");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& br) {
    out << br.getName() << ", bureaucrat grade " << br.getGrade() << '.';
    return out;
}

