#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat p("taha", 100);
        Bureaucrat m;
        m = p;
        std::cout << m << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &l){
        std::cerr << l.what();
    }
    catch (const Bureaucrat::GradeTooLowException &l){
        std::cerr << l.what();
    }
    
}
       