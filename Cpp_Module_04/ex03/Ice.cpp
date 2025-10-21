#include "Ice.hpp"

Ice::Ice()
{
    std::cout << "ice default constructor is called!" << std::endl;
    this->type = "ice";
}

Ice::Ice(const Ice &I) : AMateria()
{
    *this = I;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Ice *Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::string Ice::getType() const
{
    return this->type;
}

Ice::~Ice()
{
    
}
