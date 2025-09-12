#include "PhoneBook.hpp"

void    PhoneBook::addSpace(int len)
{
    while (len < 10)
    {
        std::cout << " ";
        len++;
    }
}

std::string PhoneBook::newString(std::string s)
{
    std::string new_str;
    if (s.length() > 10)
        return (new_str = s.substr(0, 9) + ".");
    return (s);
}

void    PhoneBook::printSpecialIndex(int in)
{
    std::cout << "First Name : " << contacts[in].getFirstName() << std::endl;
    std::cout << "Last Name : " << contacts[in].getLastName() << std::endl;
    std::cout << "Nick Name : " << contacts[in].getNickName() << std::endl;
    std::cout << "Phone Number : " << contacts[in].getPhone() << std::endl;
    std::cout << "Darkest Secret : " << contacts[in].getSecret() << std::endl;
}

int    PhoneBook::isPrintableString(std::string s)
{
    for(size_t i = 0; i < s.size(); i++)
    {
        if (!isprint((char)s[i]))
            return (0);
    }
    return (1);
}

int     PhoneBook::isDigitNumber(std::string s)
{
    for(size_t i = 0; i < s.size(); i++)
    {
        if (!isdigit((char)s[i]))
            return (0);
    }
    return (1);
}