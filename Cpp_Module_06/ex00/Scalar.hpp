#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <limits>
#include <cstdlib>
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