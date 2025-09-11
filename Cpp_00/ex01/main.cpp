#include "Phonebook.hpp"

int main()
{
    Phonebook pb;
    std::string input;
    int i;

    i = 0;
    while (input != "EXIT")
    {
        std::cout << "Enter A Command > ";
        std::getline(std::cin, input);
        if (input == "ADD")
            pb.add();
        else if (input == "SEARCH")
            pb.display();
    }
    return (0);
}
