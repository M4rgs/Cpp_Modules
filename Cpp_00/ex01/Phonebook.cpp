#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    return ;
}
Phonebook::~Phonebook(void)
{
    return ;
}

int Phonebook::checkpb(Phonebook pb)
{
    int i = 0;
    while (i < 8)
    {
        if (pb.contact[i].isnull(pb.contact[i]))
            break ;
        i++;
    }
    return (i);
}
void    Phonebook::display(Phonebook pb)
{
    std::cout << "here" << std::endl;
    return ;
}