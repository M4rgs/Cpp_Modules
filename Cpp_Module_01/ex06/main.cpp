#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Invalid arguments" << std::endl;
        return (1);
    }
    Harl harlFiler;
    harlFiler.complain(av[1]);
    return (0);
}
