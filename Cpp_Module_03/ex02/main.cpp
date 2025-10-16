#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << "\n===== TEST 3: FragTrap =====\n";
	FragTrap f("Fraggy");
	f.attack("Target C");
	f.takeDamage(50);
	f.beRepaired(25);
	f.highFivesGuys();
}