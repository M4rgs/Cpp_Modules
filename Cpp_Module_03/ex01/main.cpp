#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("ClapAttacker");
    ScavTrap scav("ScavAttarcker");

    scav.attack("Enemy");
    clap.attack("Enemy");
    scav.beRepaired(10);
    clap.beRepaired(5);
    scav.attack("Enemy");
    clap.attack("Enemy");

    scav.guardGate();

}