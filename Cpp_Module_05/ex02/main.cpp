#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    {
        Bureaucrat br("Shrubbery", 9);

        ShrubberyCreationForm fr("testForm");

        fr.beSigned(br);
        br.executeForm(fr);

    }
    std::cout << std::endl;
    {
        Bureaucrat br("Robotomy", 9);

        RobotomyRequestForm brf("testForm");

        brf.beSigned(br);
        br.executeForm(brf);

    }
    std::cout << std::endl;
    {
        Bureaucrat br("President", 9);

        PresidentialPardonForm pr("testForm");

        pr.beSigned(br);
        br.executeForm(pr);

    }
}
