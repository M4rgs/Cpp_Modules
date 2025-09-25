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

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    this->numValue = intValue << this->fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    this->numValue = roundf(floatValue * (1 << this->fractionalBits));
}

Fixed &Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assigmenet operator called" << std::endl;
    this->numValue = other.numValue;
    return (*this);
}

int Fixed::getRawBits() const
{
    return this->numValue;
}

void Fixed::setRawBits(int const raw)
{
    this->numValue = raw;
}

int Fixed::toInt(void) const
{
    return this->numValue >> this->fractionalBits;
}

float Fixed::toFloat(void) const
{
    return ((float)this->numValue / (float)(1 << this->fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
