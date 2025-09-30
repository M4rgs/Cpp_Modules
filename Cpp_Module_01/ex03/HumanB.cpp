#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
    this->name = _name;
    this->isArmed = false;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    this->isArmed = true;
    std::cout << this->name << " grabbed a " << this->_weapon->getType() << std::endl;
}

void    HumanB::attack()
{
    if (this->isArmed)
        std::cout << this->name << " attack with his " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->name << " cant find a weapn" << std::endl;
}

HumanB::~HumanB()
{
    return ;
}