#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default constructor called !" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap Paramitrized constructor called !" << std::endl;
    this->setHit(100);
    this->setEner(50);
    this->setDam(20);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() 
              << " is now in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getHit() <= 0)
    {
        std::cout << "ScavTrap " << this->getName() 
                  << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (this->getEner() <= 0)
    {
        std::cout << "ScavTrap " << this->getName() 
                  << " has no energy points left to attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->getName() 
              << " attacks " << target 
              << ", causing " << this->getDam() << " points of damage!" 
              << std::endl;
    this->setEner(this->getEner() - 1);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called !" << std::endl;
}