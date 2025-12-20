#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base *generate(void)
{
    srand(time(0));
    int r = rand() % 3;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The type is A !" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The type is B !" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The type is C !" << std::endl;
    else
        std::cout << "Unknown type !" << std::endl;
}

void identify(Base& p)
{
    try{
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "The type is A !" << std::endl;
    }
    catch (...)
    {
    }
    try{
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "The type is B !" << std::endl;
    }
    catch (...)
    {
    }
    try{
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "The type is C !" << std::endl;
    }
    catch (...)
    {
    }
}
