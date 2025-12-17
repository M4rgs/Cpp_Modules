#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        target = other.target;
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    srand(time(0));
    int ran = rand();
    if (ran % 2 == 0)
        std::cout << "* drilling noises *, " << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed\n"; 
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}