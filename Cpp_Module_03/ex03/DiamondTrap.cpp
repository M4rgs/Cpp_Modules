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
	ClapTrap::name = _name + "_clap_name";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &_copy)
{
	std::cout << "DiamondTrap copy constructor is called!" << std::endl;
	*this = _copy;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &dt)
{
	std::cout << "DiamondTrap assignement operator is called!" << std::endl;
	this->name = dt.name;
	this->ClapTrap::name = dt.ClapTrap::name;
	this->hitPoints = dt.hitPoints;
	this->energyPoints = dt.energyPoints;
	this->attackDamage = dt.attackDamage;
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap name :" << ClapTrap::name << std::endl;
	std::cout << "DiamondTrap name :" << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called !" << std::endl;
}

