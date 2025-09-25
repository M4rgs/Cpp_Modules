
#ifndef POINT_HPP   
#define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        Fixed const        x;
        Fixed const        y;
    public:
        Point();
        Point(float const _x, float const _y);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();

        Fixed x_getter() const;
        Fixed y_getter() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif