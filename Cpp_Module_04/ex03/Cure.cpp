#include "Cure.hpp"

Cure::Cure()
{
    std::cout << "Cure default constructor is called!" << std::endl;
    this->type = "cure";
}

Cure::Cure(const Cure &I) : AMateria()
{
    *this = I;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Cure *Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

std::string Cure::getType() const
{
    return this->type;
}

Cure::~Cure()
{
    
}
