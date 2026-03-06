#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage : ./RPN <Polish>" << std::endl;
        return 1;
    }
    RPN rpn;
    if (!rpn.checkRPN(av[1]))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    rpn.execRPN(av[1]);
}