#include "Scalar.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

void ScalarConverter::convert(const std::string input)
{

    int inte = 0;
    double dbl = 0;
    float flt = 0;
    char chr = 0;

    int bb = atoi(input.c_str());
    inte = bb;
    dbl = static_cast<char>(bb);
    flt = static_cast<double>(bb);
    chr = static_cast<char>(bb);

    std::cout << "as int : " << inte << "\n" << "as double : " << dbl << "\n" << "as float : " << flt << "\n" << "as char : " << chr << std::endl;
}

ScalarConverter::~ScalarConverter()
{
}
