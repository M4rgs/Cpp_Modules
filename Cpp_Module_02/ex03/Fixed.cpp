#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
    return (one.getRawBits() < two.getRawBits() ? one:two);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
{
   return (one.getRawBits() < two.getRawBits() ? one:two);
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
    return (one.getRawBits() > two.getRawBits() ? one:two);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
{
    return (one.getRawBits() > two.getRawBits() ? one:two);
}

Fixed::Fixed()
{
    this->numValue = 0;
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed::Fixed(const int intValue) 
{
    this->numValue = intValue << this->fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    this->numValue = roundf(floatValue * (1 << this->fractionalBits));
}

Fixed &Fixed::operator=(const Fixed& other)
{
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
    return (float)this->numValue / (1 << this->fractionalBits);
}

bool Fixed::operator>(Fixed other)
{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(Fixed other)
{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(Fixed other)
{
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(Fixed other)
{
   return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(Fixed other)
{
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(Fixed other)
{
    return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator*(Fixed other) const
{
    Fixed rzlt;
    rzlt.setRawBits(this->getRawBits() * other.getRawBits() / 256);
    return (rzlt);
}

Fixed Fixed::operator+(const Fixed other) const
{
    Fixed rzlt;
    rzlt.setRawBits(this->getRawBits() + other.getRawBits());
    return (rzlt);
}

Fixed Fixed::operator-(const Fixed other) const
{
    Fixed rzlt;
    rzlt.setRawBits(this->getRawBits() - other.getRawBits());
    return (rzlt);
}

Fixed Fixed::operator/(const Fixed other) const
{
    Fixed rzlt;
    rzlt.setRawBits(this->getRawBits() / other.getRawBits() * 256);
    return (rzlt);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->numValue++;
    return (tmp);
}

Fixed Fixed::operator++()
{
    this->numValue++;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->numValue--;
    return (tmp);
}

Fixed Fixed::operator--()
{
    this->numValue--;
    return(*this);
}

Fixed::~Fixed()
{
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
