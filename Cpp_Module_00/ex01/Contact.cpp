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

void    Contact::setFirstName(std::string string)
{
    this->firstName = string;
}
void    Contact::setLastName(std::string string)
{
    this->lastName = string;
}
void    Contact::setNickName(std::string string)
{
    this->nickName = string;
}
void    Contact::setPhone(std::string string)
{
    this->phone = string;
}
void    Contact::setSecret(std::string string)
{
    this->secret = string;
}

Contact::~Contact(void)
{
    return ;
}
