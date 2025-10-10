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
        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;


        Fixed& operator=(const Fixed& other);
        bool   operator>(Fixed other) const;
        bool   operator>=(Fixed other) const;
        bool   operator<(Fixed other) const;
        bool   operator<=(Fixed other) const;
        bool   operator==(Fixed other) const;
        bool   operator!=(Fixed other) const;
        

        Fixed  operator+(Fixed other) const;
		Fixed  operator-(Fixed other) const;
		Fixed  operator*(Fixed other) const;
		Fixed  operator/(Fixed other) const;
        
        Fixed  operator++(int);
        Fixed  operator--(int);
        Fixed  operator++();
        Fixed  operator--();


        static Fixed&       min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif