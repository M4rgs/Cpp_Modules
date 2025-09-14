#include "Weapon.hpp"

Weapon::Weapon(const std::string &_weapon)
{
    this->setType(_weapon);
}

std::string  Weapon::getType() const
{
    return this->type;
}

void    Weapon::setType(const std::string &_weapon)
{
    this->type = _weapon;
}
