#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private :
        AMateria    *inventory[4];
        std::string  name;
        AMateria** floor;
        int floorCount;
    public :
        Character(std::string name);
        Character(const Character &other);
        Character &operator=(const Character &other);
        ~Character();

        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif