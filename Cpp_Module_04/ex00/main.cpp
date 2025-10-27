#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "------------Animal test--------------\n";
    const Animal* meta = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    std::cout << d->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;
    d->makeSound();
    c->makeSound();
    meta->makeSound();
    delete meta;
    delete d;
    delete c;

    std::cout << std::endl;

    std::cout << "----- Wrong Example -----" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;
}
