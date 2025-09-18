#include "Zombie.hpp"

int main()
{
    int n = 5;
    Zombie *Horde = zombieHorde(n, "Taha");

    for(int i = 0; i < n; i++)
        Horde[i].announce();

    delete[] Horde;
}