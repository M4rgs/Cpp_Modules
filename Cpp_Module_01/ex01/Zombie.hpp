#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    private:
        std::string name;
    public:

        Zombie(void);
        Zombie(std::string n);

        void setName(std::string n);
        void announce(void);

        ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif