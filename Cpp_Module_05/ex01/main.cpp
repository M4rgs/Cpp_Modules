#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat br("taha", 3);
        Form    fr("form1", 6, 5);
        std::cout << fr;
        br.signForm(fr);
        std::cout << fr;
        br.signForm(fr);
    }
    catch(const Form::GradeTooLowException &e){
        std::cerr << e.what();
    }
    catch(const Form::GradeTooHighException &e){
        std::cerr << e.what();
    }
    catch(const Bureaucrat::GradeTooLowException &e){
        std::cerr << e.what();
    }
    catch(const Bureaucrat::GradeTooHighException &e){
        std::cerr << e.what();
    }
}