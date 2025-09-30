#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("baghdadi");
    ScavTrap scav("taha");
    FragTrap frag("oussama");

    scav.attack("mza7a");
    clap.attack("kapitcha");
    frag.attack("hsna");


}