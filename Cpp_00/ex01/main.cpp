#include "Phonebook.hpp"

int main()
{
    Phonebook pb;
    std::string input;
    int i;

    i = 0;
    while (1)
    {
        std::cout << "INPUT : ";
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            
        }
        else if (input == "SEARCH")
        {
            pb.display();
        }
        else if (input == "EXIT")
            break;
    }
    return 0;
}