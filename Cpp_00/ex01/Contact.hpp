#ifndef CONTACT_HPP
#define CONTACT_HPP

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
    ~Contact();

    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhone();
    std::string getSecret();

    void set_FirstName(std::string s);
    void set_LastName(std::string s);
    void set_NickName(std::string s);
    void set_Phone(std::string s);
    void set_Secret(std::string s);
};

#endif
