#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    Cure();
    Cure(const Cure& other);
    Cure &operator=(const Cure &other);
    ~Cure();

    Cure* clone() const;
    std::string getType() const;
    void use(ICharacter& target);
};

#endif