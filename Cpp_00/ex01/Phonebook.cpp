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
            std::cout << "Successfully Added To Contact" << std::endl;
        }
    }
    this->index++;
}

void Phonebook::display()
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
        add_space(1);
        std::cout << i;
        std::cout << "|";
        add_space(new_str(contacts[i].getFirstName()).length());
        std::cout << new_str(contacts[i % 8].getFirstName());
        std::cout << "|";
        add_space(new_str(contacts[i].getLastName()).length());
        std::cout << new_str(contacts[i % 8].getLastName());
        std::cout << "|";
        add_space(new_str(contacts[i].getNickName()).length());
        std::cout << new_str(contacts[i % 8].getNickName());
        std::cout << "|" << std::endl;
    }
    std::cout << "Enter Index : ";
    std::getline(std::cin, input);
    if (atoi(input.c_str()) >= this->index || atoi(input.c_str()) < 0)
        std::cout << "Error hh\n";
    else
        print_special_index(atoi(input.c_str()));
}

