#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    return ;
}
Phonebook::~Phonebook(void)
{
    return ;
}

int Phonebook::checkpb()
{
    int i = 0;
    while (i < 8)
    {
        if (contacts[i].isnull())
            break ;
        i++;
    }
    return (i);
}
void Phonebook::display()
{
    for (int i = 0; i < 8; i++)
    {
        if (!contacts[i].isnull())
        {
            std::cout << contacts[i].getFirstName() << "  ";
            std::cout << contacts[i].getLastName() << "  ";
            std::cout << contacts[i].getNickName() << " ";
            std::cout << contacts[i].getPhone() << " ";
            std::cout << contacts[i].getSecret() << " ";
            std::cout << std::endl;
        }
    }
}
