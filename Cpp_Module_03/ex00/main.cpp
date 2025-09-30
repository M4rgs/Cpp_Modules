#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("atacker");

    clap.attack("Enemy");
    clap.beRepaired(10);
    clap.attack("Enemy");
}