#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook{
    private:
        Contact contact[9];
    public:
        Phonebook();
        void    display(Phonebook pb);
        Phonebook delone(Phonebook pb);
        int checkpb(Phonebook pb);
        ~Phonebook();
};

#endif