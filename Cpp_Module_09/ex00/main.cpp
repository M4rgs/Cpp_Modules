#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

    if (ac != 2)
        return (std::cerr << "Usage : ./btc <input file>" << std::endl, 1);
    
    BitcoinExchange btc;
    try 
    {
        btc.getCsvContent("data.csv");
        btc.checkInput(av[1]);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}