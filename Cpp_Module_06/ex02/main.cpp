#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{   
    {
        Base *t = generate();
        identify(t);
        delete t;
    }
    std::cout << std::endl;
    {
        Base *t = generate();
        identify(*t);
        delete t;
    }
}