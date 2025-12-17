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

void    pritnResult(int inte, double dbl, float flt, char chr)
{
    std::cout << "as int : " << inte << std::endl;
    std::cout << "as double : " << dbl << std::endl;
    std::cout << "as float : " << flt << "f" << std::endl;
    std::cout << "as char : " << chr << std::endl;
}

bool isInt(const std::string input)
{
    size_t i = 0;
    if (input[0] == '+' || input[0] == '-')
        i = 1;
    if (i && !input[1])
        return (false);
    for (; i < input.size(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    return (true);
}

void ScalarConverter::convert(const std::string input)
{

    int inte = 0;
    double dbl = 0;
    float flt = 0;
    char chr = 0;

    if (isInt(input) == true)
    {
        inte = atoi(input.c_str());
        dbl = static_cast<double>(inte);
        flt = static_cast<float>(inte);
        chr = static_cast<char>(inte);
    }
    else
    {
        std::cout << "ERROR NOT INT !" << std::endl;
        exit (1);
    }
    pritnResult(inte, dbl, flt, chr);

}

ScalarConverter::~ScalarConverter()
{
}

