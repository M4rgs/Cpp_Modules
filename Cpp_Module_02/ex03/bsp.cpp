#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed mainArea = (a.x_getter() * (b.y_getter() - c.y_getter()) +
                       b.x_getter() * (c.y_getter() - a.y_getter()) +
                       c.x_getter() * (a.y_getter() - b.y_getter())) * Fixed(0.5f);
    if (mainArea < Fixed(0))
        mainArea = mainArea * Fixed(-1);
    Fixed area1 = (point.x_getter() * (b.y_getter() - c.y_getter()) +
                   b.x_getter() * (c.y_getter() - point.y_getter()) +
                   c.x_getter() * (point.y_getter() - b.y_getter())) * Fixed(0.5f);
    if (area1 < Fixed(0))
        area1 = area1 * Fixed(-1);
    Fixed area2 = (a.x_getter() * (point.y_getter() - c.y_getter()) +
                   point.x_getter() * (c.y_getter() - a.y_getter()) +
                   c.x_getter() * (a.y_getter() - point.y_getter())) * Fixed(0.5f);
    if (area2 < Fixed(0))
        area2 = area2 * Fixed(-1);
    Fixed area3 = (a.x_getter() * (b.y_getter() - point.y_getter()) +
                   b.x_getter() * (point.y_getter() - a.y_getter()) +
                   point.x_getter() * (a.y_getter() - b.y_getter())) * Fixed(0.5f);
    if (area3 < Fixed(0))
        area3 = area3 * Fixed(-1);

    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    Fixed epsilon(0.01f);
    Fixed sum = area1 + area2 + area3;
    Fixed diff = mainArea - sum;
    if (diff < Fixed(0))
        diff = diff * Fixed(-1);
    return (diff < epsilon);
}
