#ifndef FIXED_HPP   
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int                 numValue;
        static const int    fractionalBits;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int intValue);
        Fixed(const float floatValue);

        
        Fixed& operator=(const Fixed& other);

        int getRawBits() const;
        void setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;

        ~Fixed();


};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif