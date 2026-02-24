#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base	*generate(void)
{
	int r = std::rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void	identify(Base* p)
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

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "The type is A !" << std::endl;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "The type is B !" << std::endl;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "The type is C !" << std::endl;
	}
	catch (...)
	{
	}
}
