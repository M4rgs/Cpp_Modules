#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(10000);
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
}