#include "Point.hpp"

Fixed calculeArea(Point const &A, Point const &B, Point const &C)
{
    Fixed rzlt;

    Fixed part1 = A.x_getter() * (B.y_getter() - C.y_getter());
    Fixed part2 = B.x_getter() * (C.y_getter() - A.y_getter());
    Fixed part3 = C.x_getter() * (A.y_getter() - B.y_getter());

    rzlt = (part1 + part2 + part3) * Fixed(0.5f);

    if (rzlt < Fixed(0))
        rzlt = Fixed(-1) * rzlt;

    return rzlt;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed main(calculeArea(a, b, c));
    Fixed area_1(calculeArea(point, b, c));
    Fixed area_2(calculeArea(a, point, c));
    Fixed area_3(calculeArea(a, b, point));

    if (area_1 == Fixed(0) || area_2 == Fixed(0) || area_3 == Fixed(0))
        return false;
    if (main == area_1 + area_2 + area_3)
        return true;
    return (false);
}


