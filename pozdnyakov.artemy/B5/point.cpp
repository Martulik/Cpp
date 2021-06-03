#include "point.hpp"
#include <cmath>

namespace poz = pozdnyakov;

unsigned int poz::distance(const Point& point1, const Point& point2)
{
  return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}
