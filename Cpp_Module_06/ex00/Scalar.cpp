#include "Scalar.hpp"

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

void    pritnResult(int inte, double dbl, float flt, char chr, std::string isPossible)
{
    if (isPossible == "Impossible !")
    {
        std::cout << "as Int :\t" << isPossible << std::endl;
        std::cout << "as Double :\t" << isPossible << std::endl;
        std::cout << "as Float :\t" << isPossible << std::endl;
        std::cout << "as Char :\t" << isPossible << std::endl;
        return ;

    }
    std::cout << "as Int :\t" << inte << std::endl;
    std::cout << "as Double :\t"  << std::fixed << std::setprecision(6) << dbl << std::endl;
    std::cout << "as Float :\t" <<  std::fixed << std::setprecision(2) << flt << "f" << std::endl;
    std::cout << "as Char :\t";
    if (!(chr >= 32 && chr <= 126))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << "'" << chr << "'" << std::endl;
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

bool isDouble(std::string input)
{
    int pCount = 0;
    size_t i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < input.size(); i++)
    {
        if (pCount > 1)
            return (false);
        else if (input[i] == '.')
            pCount++;
        else if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    if (pCount != 1)
        return (false);
    return (true);
}

bool isFloat(std::string input)
{
    int pCount = 0;
    int fCount = 0;
    size_t i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < input.size(); i++)
    {
        if ((fCount > 0 && (input[i] || pCount == 0)) || pCount > 1)
            return (false);
        else if (input[i] == '.')
            pCount++;
        else if (input[i] == 'f')
            fCount++;
        else if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    if (pCount != 1 || fCount != 1)
        return (false);
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
    else if (isFloat(input) == true)
    {
        std::stringstream ss(input);
        ss >> flt;
        dbl = static_cast<double>(flt);
        inte = static_cast<double>(flt);
        chr = static_cast<double>(flt);
    }
    else if (input.size() == 1 && (input[0] >= 32 && input[0] <= 126))
    {
        chr = input[0];
        dbl = static_cast<double>(chr);
        inte = static_cast<double>(chr);
        flt = static_cast<float>(chr);
    }
    else if (isDouble(input))
    {
        std::stringstream ss(input);
        ss >> dbl;
        inte = static_cast<int>(dbl);
        flt = static_cast<float>(dbl);
        chr = static_cast<char>(dbl);
    }
    else
    {
        pritnResult(inte, dbl, flt, chr, "Impossible !");
        exit (1);
    }
    pritnResult(inte, dbl, flt, chr, "POSSIBLE");

}

ScalarConverter::~ScalarConverter()
{
}

