#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
    this->numValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assigmenet operator called" << std::endl;
    this->numValue = other.numValue;

    
    return (*this);
}

int Fixed::getRawBits()
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->numValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->numValue = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}