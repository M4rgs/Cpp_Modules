#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

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

bool Fixed::operator>(const Fixed& other) const
{
    if (this->numValue > other.numValue)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& other) const
{
    if (this->numValue < other.numValue)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->numValue >= other.numValue)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->numValue <= other.numValue)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->numValue == other.numValue)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->numValue != other.numValue)
        return (true);
    return (false);
}

Fixed::~Fixed()
{
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++this->numValue;
    return (tmp);
}

Fixed& Fixed::operator++()
{
    ++this->numValue;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --this->numValue;
    return (tmp);
}

Fixed& Fixed::operator--()
{
    --this->numValue;
    return(*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}


/*
Fixed number: 10.75
        _fractionalBits: 8
        _internal integer (_fixedPointValue): 2752

Binary (16 bits):

        Integer | Fraction
        00001010 | 11000000
          10        0.75

Conversion:
        - toFloat() -> 2752 / 256 = 10.75
        - toInt()   -> 2752 >> 8  = 10




Number: -10.743
    _fractionalBits: 8
    Step 1: Multiply by 256 -> -2748.608

Step 2: Round -> -2749
Step 3: Store as int (_fixedPointValue) -> -2749

Binary (16-bit two's complement):
    11110101.01001101  (-2749)

    toFloat() -> -2749 / 256 ≈ -10.7461
    toInt()   -> -2749 >> 8 ≈ -11

*/