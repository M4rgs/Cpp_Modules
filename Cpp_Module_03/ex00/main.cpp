#include "ClapTrap.hpp"

int main()
{
    std::cout << "\n===== TEST 1: ClapTrap =====\n";
	ClapTrap c("Clappy");
	c.attack("Target A");
	c.takeDamage(5);
	c.beRepaired(3);

}