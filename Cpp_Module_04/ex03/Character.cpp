#include "Character.hpp"

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    this->floor = NULL;
    this->floorCount = 0;
}

Character::Character(const Character &other)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    this->floor = NULL;
    this->floorCount = 0;
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->name = other.name;

        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
                delete this->inventory[i];
            this->inventory[i] = NULL;
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m->clone();
            return;
        }
    }

    AMateria** newFloor = new AMateria*[this->floorCount + 1];

    for (int i = 0; i < this->floorCount; i++)
        newFloor[i] = this->floor[i];

    newFloor[this->floorCount] = m;
    this->floorCount++;
    
    delete[] this->floor;

    this->floor = newFloor;
}


void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx]->use(target);
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !this->inventory[idx])
        return;

    AMateria** newFloor = new AMateria*[this->floorCount + 1];

    for (int i = 0; i < this->floorCount; i++)
        newFloor[i] = this->floor[i];

    newFloor[this->floorCount] = this->inventory[idx];
    this->floorCount++;

    delete[] this->floor;

    this->floor = newFloor;

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
        if (this->inventory[i])
            delete this->inventory[i];
    }
    for (int i = 0; i < this->floorCount; i++)
    {
        if (this->floor[i])
            delete this->floor[i];
    }
    delete[] this->floor;
}
