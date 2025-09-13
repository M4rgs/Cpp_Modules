#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;
    public:
        PhoneBook();
        ~PhoneBook();

        void        add();
        void        display();

        void        printSpecialIndex(int in);
        int         isPrintableString(std::string s);
        int         isDigitNumber(std::string s);
        int         isValidString(std::string input);
        std::string newString(std::string s);
};

#endif
