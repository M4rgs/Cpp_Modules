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
    search_UID();
    for (int i = 0; i < this->index; i++)
    {
            std::cout << "|";
            add_space(1);
            std::cout << i;
            std::cout << "|";
            add_space(contacts[i].getFirstName().length());
            std::cout << contacts[i].getFirstName();
            std::cout << "|";
            add_space(contacts[i].getLastName().length());
            std::cout << contacts[i].getLastName();
            std::cout << "|";
            add_space(contacts[i].getNickName().length());
            std::cout << contacts[i].getNickName();
            std::cout << "|";
            std::cout << std::endl;
    }
}

void Phonebook::add_space(int len)
{
    while (len < 10)
    {
        std::cout << " ";
        len++;
    }
    
}
void Phonebook::search_UID()
{
    int i;

    i = 0;
    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

}
