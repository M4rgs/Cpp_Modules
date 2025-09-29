#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("taha");

    scav.attack("mza7a");
    scav.beRepaired(10);
    scav.attack("mza7a");

    scav.guardGate();

}