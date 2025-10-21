#include "Character.hpp"

Character::Character(std::string name)
{
    std::cout << "Character parametrized constructor is called\n";
    this->name = name;
    for (int i = 0;i < 4;i++)
        this->invetory[i] = NULL;
}

Character::Character(const Character &C)
{
    std::cout <<  "Character copy constructor is called\n";
    for (int i = 0;i < 4;i++)
        this->invetory[i] = NULL;
    *this = C;
}

Character &Character::operator=(const Character &C)
{
    std::cout << "Character copy assignment operator is called\n";
    if (this == &C)
        return *this;
    this->name = C.name;
    for (int i = 0;i < 4;i++)
    {
        if (this->invetory[i] != NULL)
            delete this->invetory[i];
        if (C.invetory[i]  != NULL)
            this->invetory[i] = C.invetory[i]->clone();
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0;i < 4;i++)
    {
        if (this->invetory[i] != NULL)
            delete this->invetory[i];
    }
}

std::string const &Character::getName() const
{
    return this->name;
}

void    Character::equip(AMateria *m)
{
    static int idx;
    if (!m)
        return ;
    if (idx >= 4)
    {
        for (int i = 0;i < 4;i++)
        {
            if (!this->invetory[i])
            {
                idx = i;
                break;
            }
        }
    }
    if (idx < 4)
    {
        this->invetory[idx] = m;
        idx++;
    }
}

void    Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->invetory[idx])
    {
        this->invetory[idx] = NULL;
    }
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->invetory[idx])
    {
        this->invetory[idx]->use(target);
    }
}