#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
    const Point	A(2, 0);
	const Point	B(4, 5);
	const Point	C(-1, 2);
	const Point	P(0, 2);

    bool isInside = bsp(A, B, C, P);
    if (isInside)
        std::cout << "The point is Iside !" << std::endl;
    else
        std::cout << "The Point Is Outside" << std::endl;
    return 0;
}
