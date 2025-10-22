#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating animals ---" << std::endl;
    Dog originalDog;
    Cat originalCat;

    std::cout << "--- Copying animals ---" << std::endl;
    {
        Dog copyDog = originalDog;
        Cat copyCat;
        copyCat = originalCat;

        std::cout << "--- Scope end: copies will be destroyed ---" << std::endl;
    }

    std::cout << "-- Originals still alive ---" << std::endl;
}
