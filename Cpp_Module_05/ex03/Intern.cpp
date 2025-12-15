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

AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string formName, const std::string targetName)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << " now" << std::endl;
			return (all_forms[i](targetName));
		}
	}
    throw(FormNotFoundExeption());
}

const char *Intern::FormNotFoundExeption::what() const throw()
{
    return ("Form Not Found");   
}
