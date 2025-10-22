#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "Dog type : " << j->getType() << " " << std::endl;
    std::cout << "Cat type : " << i->getType() << " " << std::endl;
    
    meta->makeSound();
    j->makeSound();
    i->makeSound();
    
    const WrongAnimal* wrn = new WrongCat();
    std::cout << "WrongAnimal type : " << wrn->getType() << " " << std::endl;
    wrn->makeSound();


    delete (meta);
    delete (i);
    delete (j);
    delete (wrn);
    return 0;
}