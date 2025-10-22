#include "Character.hpp"

Character::Character(std::string name)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    this->name = name;
}

Character::Character(const Character &other)
{
    for(int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->name = other.name;
        for(int i = 0; i < 4; i++)
        {
            if (this->inventory[i] != NULL)
                delete (this->inventory[i]);
            if (other.inventory[i] != NULL)
                this->inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return ;
   for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            return;
        }
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
        this->inventory[idx]->use(target);
}


void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
        this->inventory[idx] = NULL;
}
std::string const &Character::getName() const
{
    return this->name;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
            delete(this->inventory[i]);
    }
}
