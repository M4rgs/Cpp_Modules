#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string input;

    while (input != "EXIT")
    {
        std::cout << "Enter a command > ";
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