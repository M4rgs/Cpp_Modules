#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        target = other.target;
    return *this;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}