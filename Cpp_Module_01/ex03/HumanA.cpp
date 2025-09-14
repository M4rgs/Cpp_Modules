#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& weapon) : _weapon(weapon)
{
    this->name = _name;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    return ;
}