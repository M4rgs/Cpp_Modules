#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
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

        void        setFirstName(std::string s);
        void        setLastName(std::string s);
        void        setNickName(std::string s);
        void        setPhone(std::string s);
        void        setSecret(std::string s);
};

#endif
