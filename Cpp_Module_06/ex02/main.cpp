#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{   
    std::srand(std::time(0));
    {
        for (int i = 0; i < 8; i++)
        {
            Base *t = generate();
            identify(t);
            delete t;
        }
    }
    std::cout << std::endl;
    {
       for (int i = 0; i < 8; i++)
        {
            Base *t = generate();
            identify(*t);
            delete t;
        }
    }
}