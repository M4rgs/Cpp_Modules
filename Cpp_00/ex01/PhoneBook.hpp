#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <string>
#include <cctype>

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;
    public:
        PhoneBook();
        ~PhoneBook();

        void        add();
        void        display();

        void        addSpace(int len);
        void        printSpecialIndex(int in);
        int         isPrintableString(std::string s);
        int         isDigitNumber(std::string s);
        std::string newString(std::string s);
};

#endif
