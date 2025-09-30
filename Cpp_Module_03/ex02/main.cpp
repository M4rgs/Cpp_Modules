#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("ClapAttacker");
    ScavTrap scav("ScavAttarcker");
    FragTrap frag("FragAttarcker");

    scav.attack("Enemy");
    clap.attack("Enemy");
    frag.attack("Enemy");

    scav.guardGate();
    frag.highFivesGuys();
}