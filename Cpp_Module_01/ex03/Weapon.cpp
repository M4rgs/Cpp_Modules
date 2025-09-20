#include "Weapon.hpp"

Weapon::Weapon(const std::string weaponType)
{
    this->setType(weaponType);
}

std::string const Weapon::getType() const
{
    return this->_type;
}

void    Weapon::setType(const std::string weaponType)
{
    this->_type = weaponType;
}
