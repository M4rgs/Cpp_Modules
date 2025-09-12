#include "Phonebook.hpp"

void Phonebook::add_space(int len)
{
    while (len < 10)
    {
        std::cout << " ";
        len++;
    }
}

std::string Phonebook::new_str(std::string s)
{
    std::string new_str;
    if (s.length() > 10)
        return (new_str = s.substr(0, 9) + ".");
    return (s);
}

void    Phonebook::print_special_index(int in)
{
    std::cout << "First Name : " << contacts[in].getFirstName() << std::endl;
    std::cout << "Last Name : " << contacts[in].getLastName() << std::endl;
    std::cout << "Nick Name : " << contacts[in].getNickName() << std::endl;
    std::cout << "Phone Number : " << contacts[in].getPhone() << std::endl;
    std::cout << "Darkest Secret : " << contacts[in].getSecret() << std::endl;
}

