#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor called!" << std::endl;
    this->name = "Default";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name)
{
    std::cout << "DiamondTrap parameterized constructor called!" << std::endl;
    this->name = _name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &_copy) : FragTrap(_copy), ScavTrap(_copy)
{
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
    this->name = _copy.name;
}


DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &st)
{
	std::cout << "DiamondTrap Assignement operator called!" << std::endl;
	if (this != &st)
	{
		ClapTrap::operator=(st);
		this->name = st.name; 
	}
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap name :" << ClapTrap::name << ", DiamondTrap name : " << name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called !" << std::endl;
}

