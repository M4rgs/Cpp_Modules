#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();

    AMateria* iceMateria = new Ice();
    AMateria* cureMateria = new Cure();

    src->learnMateria(iceMateria);
    src->learnMateria(cureMateria);

    delete iceMateria;
    delete cureMateria;

    ICharacter* alice = new Character("Alice");

    AMateria* tmp;

    tmp = src->createMateria("ice");
    alice->equip(tmp);
    delete tmp;
    
    tmp = src->createMateria("cure");
    alice->equip(tmp);
    delete tmp;
    
    tmp = src->createMateria("something else");
    alice->equip(tmp);
    delete tmp;


    ICharacter* bob = new Character("bob");

    alice->use(0, *bob);
    alice->use(1, *bob);
    alice->use(2, *bob); 

    alice->unequip(0);
    alice->unequip(1);

    alice->use(0, *bob);
    alice->use(1, *bob);

    delete bob;
    delete alice;
    delete src;

    return 0;
}
