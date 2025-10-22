#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "AMateria";
}

AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
    return (this->type);
}

void    AMateria::use(ICharacter &target)
{
    std::cout << "AMateria called the Use method on " << target.getName() << std::endl;
}