#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n===== TEST 1: ClapTrap =====\n";
	ClapTrap c("Clappy");
	c.attack("Target A");
	c.takeDamage(5);
	c.beRepaired(3);

	std::cout << "\n===== TEST 2: ScavTrap =====\n";
	ScavTrap s("Scavvy");
	s.attack("Target B");
	s.takeDamage(30);
	s.beRepaired(15);
	s.guardGate();
}