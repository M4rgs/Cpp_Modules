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

        void        setFirstName(std::string string);
        void        setLastName(std::string string);
        void        setNickName(std::string string);
        void        setPhone(std::string string);
        void        setSecret(std::string string);
};

#endif
