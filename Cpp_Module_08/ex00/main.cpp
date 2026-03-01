#include "easyfind.hpp"

int main()
{
    std::vector<int>p;
    p.push_back(4);
    p.push_back(5);
    p.push_back(6);
    p.push_back(7);

    int tofind;
    int easy;

    tofind = 7;
    try
    {
        easy = easyfind(p, tofind);
        std::cout << "Found element  " << easy  <<  std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    tofind = -98;
    try
    {
        easy = easyfind(p, tofind);
        std::cout << "find element  " << easy  <<  std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}