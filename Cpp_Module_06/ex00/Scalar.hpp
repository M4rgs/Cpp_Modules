#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>

class ScalarConverter {
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void convert(const std::string input);
};

#endif