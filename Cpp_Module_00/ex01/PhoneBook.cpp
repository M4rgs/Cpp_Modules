#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->index = 0;
}

void PhoneBook::add()
{
    std::string str;

    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str)))
    {
        std::cout << "Enter First Name : ";
        if (std::getline(std::cin, str) && str != "")
            this->contacts[this->index % 8].setFirstName(str);
    }
    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str)))
    {
        std::cout << "Enter Last Name : ";
        if (std::getline(std::cin, str) && str != "")
            this->contacts[this->index % 8].setLastName(str);
    }
    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str)))
    {
        std::cout << "Enter NickName : ";
        if (std::getline(std::cin, str) && str != "")
            this->contacts[this->index % 8].setNickName(str);
    }
    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str) || isValidPhoneNumber(str)))
    {
        std::cout << "Enter Phone Number : ";
        if (std::getline(std::cin, str) && str != "")
            this->contacts[this->index % 8].setPhone(str);
    }
    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str)))
    {
        std::cout << "Enter Darkest Secret : ";
        if (std::getline(std::cin, str) && str != "")
        {
            this->contacts[this->index % 8].setSecret(str);
            std::cout << "Successfully Added To Contact" << std::endl;
        }
    }
    this->index++;
}

void PhoneBook::display()
{
    int         limit;
    std::string input;

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    if (this->index > 8)
        limit = 8;
    else
        limit = this->index;
    for (int i = 0; i < limit; i++)
    {
        std::cout << "|";
        std::cout << std::setw(10) << i + 1;
        std::cout << "|";
        std::cout << std::setw(10) << newString(contacts[i % 8].getFirstName());
        std::cout << "|";
        std::cout << std::setw(10) << newString(contacts[i % 8].getLastName());
        std::cout << "|";
        std::cout << std::setw(10) << newString(contacts[i % 8].getNickName());
        std::cout << "|" << std::endl;
    }
    std::cout << " ------------------------------------------- " << std::endl;

    input = "";
    while (!std::cin.eof() && isValidString(input))
    {
        std::cout << "Enter Index : ";
        std::getline(std::cin, input);

        if (std::cin.eof()) 
            return;
        if (input == "" || isValidString(input))
            std::cout << "Error : Invalid Index" << std::endl;
    }
    printSpecialIndex(input[0] - 1 - '0');
}

PhoneBook::~PhoneBook(void)
{
    return ;
}
