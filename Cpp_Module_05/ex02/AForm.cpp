#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("def_AForm"), isSigned(false), toSignGrade(10), toExecuteGrade(10) 
{
}

AForm::AForm(const std::string& name, int toSignGrade, int toExecuteGrade) : name(name), isSigned(false), toSignGrade(toSignGrade), toExecuteGrade(toExecuteGrade)
{
    if (toSignGrade < 1 || toExecuteGrade < 1)
        throw GradeTooHighException();
    if (toSignGrade > 150 || toExecuteGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), toSignGrade(other.toSignGrade), toExecuteGrade(other.toExecuteGrade)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.getIsSigned();
    return (*this);
}

std::string AForm::getName() const 
{
    return (name);
}

int AForm::getToSignGrade() const 
{
    return (toSignGrade);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getToExecuteGrade() const
{
    return (toExecuteGrade);
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (this->getIsSigned())
        throw(FormIsAlreadySigned());
    if (b.getGrade() > this->getToSignGrade())
        throw(GradeTooLowException());
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > toExecuteGrade)
        throw GradeTooLowException();
    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high !\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low !\n");
}

const char *AForm::FormIsAlreadySigned::what() const throw()
{
    return ("AForm is already signed !\n");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("AForm is NOT signed yet !\n");
}

std::ostream& operator<<(std::ostream& out, const AForm& fr) {
    out << "AForm " << fr.getName() << ", Grade to sign : " << fr.getToSignGrade() << ", Grade to execute : " << fr.getToExecuteGrade() << ", is signed : " << (fr.getIsSigned() ? "true":"false") << "\n";
    return out;
}
