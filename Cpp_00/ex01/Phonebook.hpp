#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>

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

        void    search_UID();
        void    add_space(int len);
        void    print_special_index(int in);
        std::string new_str(std::string s);
};

#endif
