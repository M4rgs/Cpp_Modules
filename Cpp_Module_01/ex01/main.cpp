#include "Zombie.hpp"

int main()
{
    int hh = 5;
    Zombie *v = zombieHorde(hh, "Taha");

    for(int i = 0; i < hh; i++)
        v[i].announce();

    delete[] v;
}