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


void    isSpecial(std::string input, bool &isSpeci)
{
    if (input == "nan" || input == "nanf" ||
    input == "+inf" || input == "-inf" ||
    input == "+inff" || input == "-inff"|| 
    input == "inff"|| input == "inf")
    {
        isSpeci = true;
    }
}


void printDouble(double dbl, const std::string poss, bool isSpecial)
{
    std::cout << "Double :\t";
    if (isSpecial)
    {
        if (poss == "inff" ||poss == "+inff" ||poss == "-inff" || poss == "nanf")
            std::cout << poss.substr(0, poss.size() - 1) << std::endl;
        else
            std::cout << poss << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) << dbl << std::endl;
}

void printFloat(float flt, const std::string poss, bool isSpeci)
{
    std::cout << "Float  :\t";
    if (isSpeci)
    {
        if (poss == "inf" ||poss == "+inf" ||poss == "-inf" || poss == "nan")
            std::cout << poss << "f" << std::endl;
        else
            std::cout << poss << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) << flt << "f" << std::endl;
}

void    printInt(int inte, bool isOver, bool isSpeci)
{
    std::cout << "Int    :\t";
    if (isSpeci || isOver)
        std::cout << "Impossible !" << std::endl;
    else
        std::cout << inte << std::endl;    
}


void    printChar(int chr, bool isOver, bool isSpeci)
{
    std::cout << "Char   :\t";
    if (isSpeci || isOver || (chr < std::numeric_limits<char>::min() ||
         chr > std::numeric_limits<char>::max()))
        std::cout << "Impossible !" << std::endl;
    else if (!std::isprint(static_cast<char>(chr)))
        std::cout << "Non displayable !" << std::endl;
    else
        std::cout << "'" << static_cast<char>(chr) << "'" << std::endl;
    
}

void    printResult(int inte, double dbl, float flt, std::string isPossible, bool isOver, bool isSpeci)
{
    if (isPossible == "Impossible !")
    {
        std::cout << "Char   :\t" << isPossible << std::endl;
        std::cout << "Int    :\t" << isPossible << std::endl;
        std::cout << "Float  :\t" << isPossible << std::endl;
        std::cout << "Double :\t" << isPossible << std::endl;
        return ;

    }

    printChar(inte, isOver, isSpeci);

    printInt(inte, isOver, isSpeci);

    printFloat(flt, isPossible, isSpeci);

    printDouble(dbl, isPossible, isSpeci);
}

bool isInt(const std::string input, long long &tmp, bool &isOver)
{
    size_t i = 0;

    if (input[0] == '+' || input[0] == '-')
        i = 1;
    if (i == 1 && input.size() == 1)
        return (false);
    for (; i < input.size(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    std::stringstream tm(input);
    tm >> tmp;
    if (tm.fail())
        return false;
    if (tmp > (long long)std::numeric_limits<int>::max() || tmp < (long long)std::numeric_limits<int>::min())
        isOver = true;
    return (true);
}

bool isDouble(std::string input, std::string &poss)
{
    int pCount = 0;
    size_t i = 0;
    bool hasDigit = false;


    if (input == "-inf" || input == "+inf" || input == "inf" || input == "nan")
    {
        poss = input;
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
    bool hasDigit = false;

    if (input == "-inff" || input == "+inff" || input == "inff" || input == "nanf")
    {
        poss = input;
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
        else if (isdigit(input[i]))
            hasDigit = true;
        else if (input[i] == 'f')
            fCount++;
        else if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    if (pCount != 1 || fCount != 1 || !hasDigit)
        return (false);
    return (true);
}

char    isChar(std::string input)
{
    if (input.size() == 1 && (std::isprint(input[0]) && !std::isdigit(input[0])))
        return input[0];
    if (input[0] == '\'')
    {
        if (input.size() == 3 && input[2] == '\'' && (std::isprint(input[1])))
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
    bool isSpeci = false;

    std::string poss = "";

    long long tmp;
    isSpecial(input, isSpeci);
    if (isInt(input, tmp, isOver))
    {
        if (!isOver)
            inte = static_cast<int>(tmp);

        dbl = static_cast<double>(tmp);
        flt = static_cast<float>(tmp);
    }
    else if (isFloat(input, poss) == true)
    {
        if (!isSpeci)
        {
            std::stringstream ss(input);
            ss >> flt;
            if (ss.fail())
                poss = "Impossible";
        }
        dbl = static_cast<double>(flt);
        inte = static_cast<int>(flt);
    }
    else if ((chr = isChar(input)) != -1)
    {
        dbl = static_cast<double>(chr);
        inte = static_cast<int>(chr);
        flt = static_cast<float>(chr);
    }
    else if (isDouble(input, poss))
    {
        if (!isSpeci)
        {
            std::stringstream ss(input);
            ss >> dbl;
            if (ss.fail())
                poss = "Impossible";
        }
        inte = static_cast<int>(dbl);
        flt = static_cast<float>(dbl);
    }
    else
        poss = "Impossible !";
    printResult(inte, dbl, flt, poss, isOver, isSpeci);

}

ScalarConverter::~ScalarConverter()
{
}

