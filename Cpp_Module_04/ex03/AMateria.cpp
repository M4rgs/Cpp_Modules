#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "AMateria";
    std::cout << "AMateria constructor is called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
    std::cout << "AMateria parametrized constructor is called\n";
    this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria copy constructor is called\n";
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout <<  "AMateria copy assignment operator is called\n";
    if (this != &other)
        this->type = other.type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor is called\n";
}

std::string const &AMateria::getType() const
{
    return (this->type);
}

void    AMateria::use(ICharacter &target)
{
    std::cout << "AMateria called the Use method on " << target.getName() << std::endl;
}