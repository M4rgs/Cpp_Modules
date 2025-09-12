#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

std::string Contact::getFirstName()
{
    return this->firstName;
}

std::string Contact::getLastName()
{
    return this->lastName;
}

std::string Contact::getNickName()
{
    return this->nickName;
}

std::string Contact::getPhone()
{
    return this->phone;
}

std::string Contact::getSecret()
{
    return this->secret;
}

void    Contact::setFirstName(std::string s)
{
    this->firstName = s;
}
void    Contact::setLastName(std::string s)
{
    this->lastName = s;
}
void    Contact::setNickName(std::string s)
{
    this->nickName = s;
}
void    Contact::setPhone(std::string s)
{
    this->phone = s;
}
void    Contact::setSecret(std::string s)
{
    this->secret = s;
}

Contact::~Contact(void)
{
    return ;
}
