#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(float const _x, float const _y) : x(_x), y(_y)
{
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return (*this);
}

Fixed Point::x_getter() const
{
    return (this->x);
}

Fixed Point::y_getter() const
{
    return (this->y);
}

Point::~Point()
{

}

