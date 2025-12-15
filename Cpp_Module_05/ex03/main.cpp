#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() 
{
    AForm *frmt = NULL;
    try 
    {
        Intern inter;
        Bureaucrat br("T A H A", 1);
        ShrubberyCreationForm fr("ShrubberyForm");
        RobotomyRequestForm brf("RobotomyForm");
        PresidentialPardonForm pr("PresidentForm");
        frmt = inter.makeForm("shrubbery creation", "InterMilan");

        br.signForm(*frmt);
        br.signForm(fr);
        br.signForm(brf);
        br.signForm(pr);

        fr.execute(br);
        brf.execute(br);
        pr.execute(br);
        frmt->execute(br);

    }
    catch(const AForm::GradeTooLowException &e)
    {
        std::cerr << e.what();
    }
    catch(const AForm::GradeTooHighException &e)
    {
        std::cerr << e.what();
    }
    catch(const Intern::FormNotFoundExeption &e)
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
    delete frmt;
}
