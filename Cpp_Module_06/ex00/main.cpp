#include "Scalar.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Please run it as ./Scalar <args>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(std::string(av[1]));
}