#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("def_bureaucrat"), grade(10)
{
    std::cout << "Default constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
    throw(GradeTooHighException());
    else if (grade > 150)
    throw(GradeTooLowException());
    this->grade = grade;
    std::cout << "Prametrized constructor called !" << std::endl;
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

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout << "Copy constructor called !" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.getGrade();
    std::cout << "Copy assigmenet operator called !" << std::endl;
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

