#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string _name);
        FragTrap(const FragTrap &st);
        FragTrap	&operator=(const FragTrap &st);
        ~FragTrap();

        virtual void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
