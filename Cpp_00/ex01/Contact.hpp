#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone;
        std::string secret;
    public:
        Contact();
        Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone, std::string secret);
        int isnull(Contact cnt);
        ~Contact();
};

#endif