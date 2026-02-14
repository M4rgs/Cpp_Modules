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

void    printResult(int inte, double dbl, float flt, char chr, std::string isPossible, bool &isOver)
{
    if (isPossible == "Impossible !")
    {
        std::cout << "Char   :\t" << isPossible << std::endl;
        std::cout << "Int    :\t" << isPossible << std::endl;
        std::cout << "Float  :\t" << isPossible << std::endl;
        std::cout << "Double :\t" << isPossible << std::endl;
        return ;

    }

    std::cout << "Char   :\t";
    if (isPossible == "nan"|| isPossible == "inf" || isOver)
        std::cout << "Impossible !" << std::endl;
    else if (!(chr >= 32 && chr <= 126))
        std::cout << "Non displayable !" << std::endl;
    else
        std::cout << "'" << chr << "'" << std::endl;

    std::cout << "Int    :\t";
     if (isPossible == "nan" || isPossible == "inf" || isOver)
        std::cout << "Impossible !" << std::endl;
    else
        std::cout << inte << std::endl;

    std::cout << "Float  :\t";
    if (isPossible == "nan" || isPossible == "inf")
        std::cout << isPossible << "f" <<  std::endl;
    else
       std::cout <<  std::fixed << std::setprecision(1) << flt << "f" << std::endl;

    std::cout << "Double :\t"  ;
    if (isPossible == "nan" || isPossible == "inf")
        std::cout << isPossible << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << dbl << std::endl;
    
}

bool isInt(const std::string input, bool &isOver)
{
    size_t i = 0;
    long long tmp;

    if (input[0] == '+' || input[0] == '-')
        i = 1;
    if (i && !input[1])
        return (false);
    for (; i < input.size(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    std::stringstream tm(input);
    tm >> tmp;
    if (tmp > (long long)std::numeric_limits<int>::max() || tmp < (long long)std::numeric_limits<int>::min())
        isOver = true;
    return (true);
}

bool isDouble(std::string input, std::string &poss)
{
    int pCount = 0;
    size_t i = 0;
    bool hasDigit = false;

    if (input == "nan")
    {
        poss = "nan";
        return (true);
    }
    if (input == "-inf" || input == "+inf" || input == "inf")
    {
        poss = "inf";
        return true;
    }
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < input.size(); i++)
    {
        if (pCount > 1)
            return (false);
        else if (input[i] == '.')
            pCount++;
        else if (isdigit(input[i]))
            hasDigit = true;
        else if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    if (pCount != 1 || !hasDigit)
        return (false);
    return (true);
}

bool isFloat(std::string input, std::string &poss)
{
    int pCount = 0;
    int fCount = 0;
    size_t i = 0;

    if (input == "nanf")
    {
        poss = "nan";
        return (true);
    }
    if (input == "-inff" || input == "+inff" || input == "inff")
    {
        poss = "inf";
        return true;
    }
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

char    isChar(std::string input)
{
    if (input.size() == 1 && (input[0] >= 32 && input[0] <= 126))
        return input[0];
    if (input[0] == '\'')
    {
        if (input.size() == 3 && input[2] == '\'' && (input[1] >= 32 && input[1] <= 126))
            return input[1];
    } 
    return -1;
}

void ScalarConverter::convert(const std::string input)
{

    int inte = 0;
    double dbl = 0;
    float flt = 0;
    char chr = 0;
    bool isOver = false;

    std::string poss = "";

    if (isInt(input, isOver) == true)
    {
        inte = atoi(input.c_str());
        dbl = static_cast<double>(inte);
        flt = static_cast<float>(inte);
        chr = static_cast<char>(inte);
    }
    else if (isFloat(input, poss) == true)
    {
        if (poss != "nan" || poss == "inf")
        {
            std::stringstream ss(input);
            ss >> flt;
        }
        dbl = static_cast<double>(flt);
        inte = static_cast<int>(flt);
        chr = static_cast<char>(flt);
    }
    else if ((chr = isChar(input)) != -1)
    {
        dbl = static_cast<double>(chr);
        inte = static_cast<int>(chr);
        flt = static_cast<float>(chr);
    }
    else if (isDouble(input, poss))
    {
        if (poss != "nan" || poss == "inf")
        {
            std::stringstream ss(input);
            ss >> dbl;
        }
        inte = static_cast<int>(dbl);
        flt = static_cast<float>(dbl);
        chr = static_cast<char>(dbl);
    }
    else
        poss = "Impossible !";
    printResult(inte, dbl, flt, chr, poss, isOver);

}

ScalarConverter::~ScalarConverter()
{
}

