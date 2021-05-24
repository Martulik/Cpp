#include "shape.hpp"

#include <iostream>

std::ostream& pochernin::operator<<(std::ostream& out, const Point& point)
{
  out << "(" << point.x << "; " << point.y << ")";
  return out;
}
