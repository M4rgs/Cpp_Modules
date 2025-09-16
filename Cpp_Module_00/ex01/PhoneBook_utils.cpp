#include "PhoneBook.hpp"

std::string PhoneBook::newString(std::string string)
{
    std::string new_str;
    if (string.length() > 10)
        return (new_str = string.substr(0, 9) + ".");
    return (string);
}

void    PhoneBook::printSpecialIndex(int in)
{
    std::cout << "First Name : " << contacts[in].getFirstName() << std::endl;
    std::cout << "Last Name : " << contacts[in].getLastName() << std::endl;
    std::cout << "Nick Name : " << contacts[in].getNickName() << std::endl;
    std::cout << "Phone Number : " << contacts[in].getPhone() << std::endl;
    std::cout << "Darkest Secret : " << contacts[in].getSecret() << std::endl;
}

int    PhoneBook::isPrintableString(std::string string)
{
    for(size_t i = 0; i < string.size(); i++)
    {
        if (!isprint((char)string[i]))
            return (0);
    }
    return (1);
}

int     PhoneBook::isDigitNumber(std::string string)
{
    for(size_t i = 0; i < string.size(); i++)
    {
        if (!isdigit((char)string[i]))
            return (0);
    }
    return (1);
}
int     PhoneBook::isValidString(std::string input)
{
    if (input == ""
    ||!isPrintableString(input)
    || !isDigitNumber(input)
    || input[0] < '1'
    || input[0] > '8'
    || input.size() > 1
    || contacts[input[0] - 1 - '0'].getFirstName().size() == 0)
        return (1);
    return (0);
}

int     PhoneBook::isValidPhoneNumber(std::string input)
{
	for (int i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]))
		{
			std::cout << "The NumberPhone Must Contains Only Digits " << std::endl;
			return (1);
		}
	}
    return (0);
}
