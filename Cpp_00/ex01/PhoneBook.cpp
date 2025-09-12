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
        if (std::getline(std::cin, str) && str != "" && isPrintableString(str))
            this->contacts[this->index % 8].set_FirstName(str);
    }
    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str)))
    {
        std::cout << "Enter Last Name : ";
        if (std::getline(std::cin, str) && str != "" && isPrintableString(str))
            this->contacts[this->index % 8].set_LastName(str);
    }
    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str)))
    {
        std::cout << "Enter NickName : ";
        if (std::getline(std::cin, str) && str != "" && isPrintableString(str))
            this->contacts[this->index % 8].set_NickName(str);
    }
    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str)))
    {
        std::cout << "Enter Phone Number : ";
        if (std::getline(std::cin, str) && str != "" && isPrintableString(str))
            this->contacts[this->index % 8].set_Phone(str);
    }
    str = "";
    while (!std::cin.eof() && (str == "" || !isPrintableString(str)))
    {
        std::cout << "Enter Phone Secret : ";
        if (std::getline(std::cin, str) && str != "" && isPrintableString(str))
        {
            this->contacts[this->index % 8].set_Secret(str);
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
        addSpace(1);
        std::cout << i;
        std::cout << "|";
        addSpace(newString(contacts[i].getFirstName()).length());
        std::cout << newString(contacts[i % 8].getFirstName());
        std::cout << "|";
        addSpace(newString(contacts[i].getLastName()).length());
        std::cout << newString(contacts[i % 8].getLastName());
        std::cout << "|";
        addSpace(newString(contacts[i].getNickName()).length());
        std::cout << newString(contacts[i % 8].getNickName());
        std::cout << "|" << std::endl;
    }
    std::cout << "Enter Index : ";
    std::getline(std::cin, input);
    if (!isDigitNumber(input) || atoi(input.c_str()) >= this->index)
        std::cout << "Error : Invalid Index" << std::endl;
    else
        printSpecialIndex(atoi(input.c_str()));
}

PhoneBook::~PhoneBook(void)
{
    return ;
}
