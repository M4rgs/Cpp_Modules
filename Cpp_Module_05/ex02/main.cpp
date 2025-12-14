#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    try 
    {
        Bureaucrat br("T A H A", 9);
        ShrubberyCreationForm fr("ShrubberyForm");
        RobotomyRequestForm brf("RobotomyForm");
        PresidentialPardonForm pr("PresidentForm");

        br.signForm(fr);
        br.signForm(brf);
        br.signForm(pr);

        fr.execute(br);
        brf.execute(br);
        pr.execute(br);

    }
    catch(const AForm::GradeTooLowException &e)
    {
        std::cerr << e.what();
    }
    catch(const AForm::GradeTooHighException &e)
    {
        std::cerr << e.what();
    }
    catch(const AForm::FormNotSignedException &e)
    {
        std::cerr << e.what();
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what();
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what();
    }
}
