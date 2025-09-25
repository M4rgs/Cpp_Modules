#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
    const Point	A(2, 0);
	const Point	B(4, 5);
	const Point	C(-1, 2);
	const Point	P(0, 2);

    std::cout << "The Point is " << (bsp(A, B, C, P) ? "inside" : "outside") << std::endl;
    return 0;
}
