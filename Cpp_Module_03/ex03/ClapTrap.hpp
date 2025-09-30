#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>


class ClapTrap{
    protected:
        std::string         name;
        unsigned int         hitPoints;
        unsigned int         energyPoints;
        unsigned int         attackDamage;
    public:
        ClapTrap();
        ~ClapTrap();

        ClapTrap(std::string _name);
        
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        void    setHit(unsigned int i);
        void    setEner(unsigned int i);
        void    setDam(unsigned int i);

        unsigned int    getHit();
        unsigned int    getEner();
        unsigned int    getDam();
        std::string    getName();
};


#endif