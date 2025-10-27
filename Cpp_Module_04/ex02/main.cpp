#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    int i = 4;

    Animal *an[i];

    for (int j = 0; j < i; j++)
    {
        if (j % 2 == 0)
            an[j] = new Cat();
        else
            an[j] = new Dog();
    }

    std::cout << std::endl;

    for (int j = 0; j < i; j++)
        std::cout << "Animal type : " << an[j]->getType() << std::endl;

    std::cout << std::endl;

    for(int j = 0; j < i; j++)
        delete an[j];

    std::cout << std::endl;

    std::cout << "------------Animal test--------------\n";
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    std::cout << d->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;
    d->makeSound();
    c->makeSound();

    delete d;
    delete c;

    std::cout << std::endl;

    std::cout << "----- Wrong Example -----" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;

}
