#include "Zombie.hpp"

int main()
{
    Zombie *z = newZombie("NameOne");

    z->announce();
    randomChump("NameTwo");
    delete z;
}