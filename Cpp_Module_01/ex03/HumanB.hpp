#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon *_weapon;
        bool isArmed;
    public:
        HumanB(std::string _name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &weapon);
};

#endif