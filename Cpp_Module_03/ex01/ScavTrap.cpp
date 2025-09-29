#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
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

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->getHit() > 0)
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target;
        this->takeDamage(this->getDam());
        this->setEner(this->getEner() - 1);
    }
    else
        std::cout << "No enough hit point for ScavTrap to attack !" << std::endl;
    
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called !" << std::endl;
}