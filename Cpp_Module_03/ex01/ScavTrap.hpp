#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

    public:
        ScavTrap();
        ~ScavTrap();
    
        ScavTrap(std::string _name);

        void attack(const std::string& target);
        void guardGate();

};

#endif