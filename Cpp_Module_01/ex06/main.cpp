#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Invalid arguments" << std::endl;
        return (1);
    }
    Harl harlFilter = Harl(av[1]);
    harlFilter.complain();
    return (0);
}
