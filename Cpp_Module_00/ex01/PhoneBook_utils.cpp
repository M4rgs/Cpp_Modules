#include "PhoneBook.hpp"

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
int     PhoneBook::isValidString(std::string input)
{
    if (input == ""
    ||!isPrintableString(input)
    || !isDigitNumber(input)
    || atoi(input.c_str()) < 1
    || atoi(input.c_str()) > 8
    || atoi(input.c_str()) > this->index
    || input.size() > 1)
        return (1);
    return (0);
}