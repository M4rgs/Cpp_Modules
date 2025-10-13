#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{

    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(const ScavTrap &st);
        ScavTrap	&operator=(const ScavTrap &st);
        ScavTrap(std::string _name);

        virtual void attack(const std::string& target);
        void guardGate();

};

#endif