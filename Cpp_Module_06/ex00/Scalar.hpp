#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>

class ScalarConverter {
    public :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static void convert(const std::string input);
};

#endif