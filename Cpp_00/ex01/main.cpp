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
        if (input == "EXIT")
            break;
        else if (input == "ADD")
        {
            i = pb.checkpb(pb);
            if (i < 7)
            {
                
                break;
            }
        }
    }
    return 0;
}