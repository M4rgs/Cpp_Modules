#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone, std::string secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nick_name = nick_name;
    this->phone = phone;
    this->secret = secret;
}


Contact::~Contact(void)
{
    return ;
}

int Contact::isnull(Contact ctn)
{
    if (ctn.first_name.empty())
        return (1);
    return (0);
}

