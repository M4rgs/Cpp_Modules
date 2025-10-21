#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "AMateria";
    std::cout << "AMateria constructor is called\n";
}

AMateria::AMateria(std::string const & _type)
{
    std::cout << "AMateria parametrized constructor is called\n";
    this->type = _type;
}

AMateria::AMateria(const AMateria &A)
{
    std::cout << "AMateria copy constructor is called\n";
    *this = A;
}

AMateria &AMateria::operator=(const AMateria &A)
{
    std::cout <<  "AMateria copy assignment operator is called\n";
    if (this == &A)
        return *this;
    this->type = A.type;
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