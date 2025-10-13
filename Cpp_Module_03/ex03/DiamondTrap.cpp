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

DiamondTrap::DiamondTrap(std::string _name) 
{
    std::cout << "DiamondTrap parameterized constructor called!" << std::endl;
	name = _name;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << ClapTrap::name << " and " << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called !" << std::endl;
}

