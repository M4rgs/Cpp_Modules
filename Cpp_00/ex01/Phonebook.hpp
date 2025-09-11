#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
    private:
        Contact contacts[8];
        int     index;
    public:
        Phonebook();
        ~Phonebook();

        void    add();
        void    search();
        void    display();

        Contact	get_contact(int index);
};

#endif
