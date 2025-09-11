#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

std::string Contact::getFirstName()
{
    return this->first_name;
}

std::string Contact::getLastName()
{
    return this->last_name;
}

std::string Contact::getNickName()
{
    return this->nick_name;
}

std::string Contact::getPhone()
{
    return this->phone;
}

std::string Contact::getSecret()
{
    return this->secret;
}

void    Contact::set_FirstName(std::string s)
{
    this->first_name = s;
}
void    Contact::set_LastName(std::string s)
{
    this->last_name = s;
}
void    Contact::set_NickName(std::string s)
{
    this->nick_name = s;
}
void    Contact::set_Phone(std::string s)
{
    this->phone = s;
}
void    Contact::set_Secret(std::string s)
{
    this->secret = s;
}

Contact::~Contact(void)
{
    return ;
}
