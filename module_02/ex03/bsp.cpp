#include "Point.hpp"

Fixed abs_fixed(Fixed value)
{
    return (value < 0) ? value * -1 : value;
}

static Fixed area(Point const a, Point const b, Point const c)
{
  return ((((a.getX() * b.getY()) + (b.getX() * c.getY()) + (c.getX() * a.getY())) - 
            ((a.getX() * c.getY()) + (c.getX() * b.getY()) + (b.getX() * a.getY())))/2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = abs_fixed(area(a, b, c));

    Fixed area1 = abs_fixed(area(point, a, b));
    Fixed area2 = abs_fixed(area(point, b, c));
    Fixed area3 = abs_fixed(area(point, c, a));

    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    return totalArea == area1 + area2 + area3;
}
