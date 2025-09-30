#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default contructor called !" << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap Paramitrized constructor called !" << std::endl;
    this->setHit(100);
    this->setEner(100);
    this->setDam(30);
}

void    FragTrap::attack(const std::string& target)
{
    if (this->getHit() > 0)
    {
        std::cout << "FragTrap " << this->getName() << " attacks " << target;
        this->takeDamage(this->getDam());
        this->setEner(this->getEner() - 1);
    }
    else
        std::cout << "No enough hit point for FragTrap to attack !" << std::endl;
    
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "HighFigh !" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called !" << std::endl;
}
