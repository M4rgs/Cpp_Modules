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
    std::cout << "* drilling noises *" << std::endl;
    std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}