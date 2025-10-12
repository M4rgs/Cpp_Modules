#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string _name);
        FragTrap(const FragTrap &st);
        FragTrap	&operator=(const FragTrap &st);
        ~FragTrap();

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
