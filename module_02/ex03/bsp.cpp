#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
  return ( (b.getX() - a.getX()) * (c.getY() - a.getY())
          - (b.getY() - a.getY()) * (c.getX() - a.getX()) );
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = area(a, b, c);

    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);

    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    if ((area1 > 0 && area2 > 0 && area3 > 0) ||
        (area1 < 0 && area2 < 0 && area3 < 0))
        return true;

    return false;
}