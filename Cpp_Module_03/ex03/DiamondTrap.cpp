#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = "Default";
	ClapTrap::name = "Default_clap_name";
	std::cout << "DiamondTrap Default constructor is called!" << std::endl;;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}
