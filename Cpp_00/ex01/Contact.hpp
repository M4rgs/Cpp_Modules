#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone;
    std::string secret;

public:
    Contact();
    Contact(std::string first_name, std::string last_name,
            std::string nick_name, std::string phone, std::string secret);
    ~Contact();

    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhone();
    std::string getSecret();

    int isnull();
};

#endif
