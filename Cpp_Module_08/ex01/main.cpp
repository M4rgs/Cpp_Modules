#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(20);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span : " <<  sp.shortestSpan() << std::endl;
        std::cout << "Biggest Span : " <<  sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::vector<int> p;
    p.push_back(34);
    p.push_back(54);
    p.push_back(64);
    p.push_back(87);
    p.push_back(78);
    try
    {
        Span ss = Span(20);
        ss.addNumbers(p.begin(), p.end());
        std::cout << "Shortest Span : " <<  ss.shortestSpan() << std::endl;
        std::cout << "Biggest Span : " <<  ss.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}