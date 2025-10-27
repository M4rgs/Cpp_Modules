#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0;i < 4;i++)
        this->slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0;i < 4;i++)
        this->slot[i] = NULL;
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            if (this->slot[i])
                delete(this->slot[i]);
            if (other.slot[i])
                this->slot[i] = other.slot[i]->clone();
        }
    }
    return *this;
}
void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i] == NULL)
        {
            this->slot[i] = m->clone();
            return;
        }
    }
}

AMateria    *MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i] != NULL && this->slot[i]->getType() == type)
        {
            return (this->slot[i]->clone());
        }
    }
    std::cout << type << " doesnt exist in the slot" << std::endl;
    return NULL;
}


MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] != NULL)
            delete (this->slot[i]);
    }
}