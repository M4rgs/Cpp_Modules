#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called!" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap parameterized constructor called!" << std::endl;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = ft;
}

FragTrap	&FragTrap::operator=(const FragTrap &ft)
{
	std::cout << "FragTrap Assignement operator called!" << std::endl;
	this->name = ft.name;
	this->hitPoints = ft.hitPoints;
	this->energyPoints = ft.energyPoints;
	this->attackDamage = ft.attackDamage;
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "FragTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << name << " attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five !" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called !" << std::endl;
}
