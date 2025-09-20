#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

void Zombie::setName(std::string _name)
{
    this->name = _name;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << ": Destroyed..." << std::endl;
}
