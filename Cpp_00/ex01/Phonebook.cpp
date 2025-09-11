#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->index = 0;
    return ;
}
Phonebook::~Phonebook(void)
{
    return ;
}

void Phonebook::add()
{
    std::string str;

        str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter First Name : ";
        if (std::getline(std::cin, str) && str != "")
            this->contacts[this->index % 8].set_FirstName(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter Last Name : ";
        if (std::getline(std::cin, str) && str != "")
            this->contacts[this->index % 8].set_LastName(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter NickName : ";
        if (std::getline(std::cin, str) && str != "")
            this->contacts[this->index % 8].set_NickName(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter Phone Number : ";
        if (std::getline(std::cin, str) && str != "")
            this->contacts[this->index % 8].set_Phone(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter Phone Secret : ";
        if (std::getline(std::cin, str) && str != "")
        {
            this->contacts[this->index % 8].set_Secret(str);
            std::cout << "Succeflly Added To Contact" << std::endl;
        }
    }
    this->index++;
}

void Phonebook::display()
{
    for (int i = 0; i < this->index; i++)
    {
            std::cout << contacts[i].getFirstName() << " index of : " << this->index << std::endl;
            std::cout << contacts[i].getLastName() << " index of : " << this->index << std::endl;
            std::cout << contacts[i].getNickName() << " index of : " << this->index << std::endl;
            std::cout << contacts[i].getPhone() << " index of : " << this->index << std::endl;
            std::cout << contacts[i].getSecret() << " index of : " << this->index << std::endl;
            std::cout << std::endl;
    }
}

void Phonebook::search_UID()
{
    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    std::cout << " ------------------------------------------- " << std::endl;
}
