#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "ice default constructor is called!" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    *this = other;
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
    std::cout << "Ice destructor called!" << std::endl;
}
