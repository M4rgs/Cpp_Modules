#include "iter.hpp"


void print(const char &c)
{
    std::cout << c << " ";
}


void high(char &c)
{
    c = std::toupper(c);
}

template<typename T>

void printT(T &c)
{
    std::cout << c << " ";
}

int main()
{
    char a[] = {'t', 'a', 'h', 'a'};

    std::cout << "----before iter----"<<std::endl;
    for (int i = 0; i < 4; i++)
        std::cout << a[i];
    std::cout << std::endl;

    iter(a, 4, high);

    std::cout << "----after iter----"<<std::endl;
    for (int i = 0; i < 4; i++)
        std::cout << a[i];
    std::cout << std::endl;

    char b[] = {'h', 'e', 'l', 'l', 'o'};
    std::cout << "----printing const iter----"<<std::endl;
    iter(b, 5, print);
    std::cout << std::endl;

    char v[]= "taha";
    std::cout << "----printing T function params----"<<std::endl;
    iter(v, 4, printT<char>);
    std::cout << std::endl;

}
