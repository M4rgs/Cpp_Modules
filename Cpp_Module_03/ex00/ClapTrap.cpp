#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
    std::cout << "ClapTrap Parametrized constructor called!" << std::endl;
    this->name = _name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired because it is destroyed!" << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left to repair!" << std::endl;
        return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repaired itself by " << amount
              << "! Current HP: " << hitPoints << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed" << std::endl;
        return;
    }
    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " took " << amount 
              << " damage! Remaining HP: " << hitPoints << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points left to attack" << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left to attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage" << std::endl;
    energyPoints--;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called !" << std::endl;
}