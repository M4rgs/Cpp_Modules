#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called !" << std::endl;
}


FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap Paramitrized constructor called !" << std::endl;
    this->setHit(100);
    this->setEner(100);
    this->setDam(30);
}


void FragTrap::attack(const std::string& target)
{
    if (this->getHit() <= 0)
    {
        std::cout << "FragTrap " << this->getName() 
                  << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (this->getEner() <= 0)
    {
        std::cout << "FragTrap " << this->getName() 
                  << " has no energy points left to attack!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->getName() 
              << " attacks " << target 
              << ", causing " << this->getDam() << " points of damage!" 
              << std::endl;
    this->setEner(this->getEner() - 1);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() 
              << " requests a positive high five !" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called !" << std::endl;
}
