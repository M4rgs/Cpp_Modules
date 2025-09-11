#include "Phonebook.hpp"

int main()
{
    Phonebook pb;
    std::string input;

    while (input != "EXIT")
    {
        std::cout << "Enter A Command > ";
        std::getline(std::cin, input);
        if (input == "ADD")
            pb.add();
        else if (input == "SEARCH")
            pb.display();
        if (std::cin.eof())
        {
            std::cout << std::endl;
            return (0);
        }
    }
    return (0);
}
