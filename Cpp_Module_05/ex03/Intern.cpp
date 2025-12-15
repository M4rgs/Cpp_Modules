#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern  &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}
AForm   *Intern::makeForm(const std::string formName, const std::string targetName)
{
    AForm *p = NULL;
    const char* names[] = {"skip", "robotomy request", "presidential pardon", "shrubbery creation"};
    int i = 0;

    for (; i < 4; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            break;
        }
    }

    switch (i)
    {
        case 1:
        {
            p = new RobotomyRequestForm(targetName);
            break;
        }
        case 2:
        {
            p = new PresidentialPardonForm(targetName);
            break;
        }
        case 3:
        {
            p = new ShrubberyCreationForm(targetName);
            break;
        }
        default : 
        {
            throw Intern::FormNotFoundExeption();
            break; 
        }
    }
    return (p);
}

const char *Intern::FormNotFoundExeption::what() const throw()
{
    return ("Form Not Found");   
}
