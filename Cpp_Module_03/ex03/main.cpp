#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\n===== TEST 1: ClapTrap =====" << std::endl;
	ClapTrap c("Clappy");
	c.attack("Target A");
	c.takeDamage(5);
	c.beRepaired(3);

	std::cout << "\n===== TEST 2: ScavTrap =====" << std::endl;
	ScavTrap s("Scavvy");
	s.attack("Target B");
	s.takeDamage(30);
	s.beRepaired(15);
	s.guardGate();

	std::cout << "\n===== TEST 3: FragTrap =====" << std::endl;
	FragTrap f("Fraggy");
	f.attack("Target C");
	f.takeDamage(50);
	f.beRepaired(25);
	f.highFivesGuys();

	std::cout << "\n===== TEST 4: DiamondTrap =====" << std::endl;
	DiamondTrap d("Diamondy");
	d.attack("Target D");
	d.takeDamage(40);
	d.beRepaired(10);
	d.whoAmI();

	std::cout << "\n===== TEST 5: Copy and Assignment =====" << std::endl;
	DiamondTrap copy(d);
	DiamondTrap assign;
	assign = d;

	copy.whoAmI();
	assign.whoAmI();

	return 0;
}