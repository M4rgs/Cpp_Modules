#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default constructor called!" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap Parameterized constructor called!" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st)
{
    std::cout << "ScavTrap Copy constructor called!" << std::endl;
    *this = st;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &st)
{
	std::cout << "ScavTrap Assignement operator called!" << std::endl;
    ClapTrap::operator=(st);
    return (*this);

}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name 
              << " is now in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints <= 0 || hitPoints <= 0) 
    {
        std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called !" << std::endl;
}