#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

    if (ac != 2)
        return (std::cerr << "Usage : ./btc <input file>" << std::endl, 1);
    
    BitcoinExchange btc;
    try 
    {
        btc.checkInput(av[1]);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}