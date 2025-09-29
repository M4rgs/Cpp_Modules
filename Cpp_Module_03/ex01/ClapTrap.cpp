#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called !" << std::endl;

}

ClapTrap::ClapTrap(std::string _name)
{
    std::cout << "Paramitrized constructor called !" << std::endl;
    this->name = _name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    this->hitPoints += amount;
    this->energyPoints--;
    std::cout << "ClapTrap got repaired ! Current hit points : " << this->hitPoints << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->hitPoints -= amount;
    std::cout << ", causing " << amount << " points of damage !"<< std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target;
        this->takeDamage(this->attackDamage);
        this->energyPoints--;
    }
    else
        std::cout << "No enough hit point for ClapTrap to attack !" << std::endl;
    
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called !" << std::endl;
}