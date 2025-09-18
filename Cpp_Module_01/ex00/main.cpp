#include "Zombie.hpp"

int main()
{
    Zombie *z = newZombie("NameOne");

    z->announce();
    delete z;
    randomChump("NameTwo");
}