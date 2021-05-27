#include "point.hpp"

#include <iostream>

std::ostream& razukrantov::operator<<(std::ostream& out, const Point& point)
{
  out << "(" << point.x << "; " << point.y << ")";
  return out;
}

std::istream& razukrantov::operator>>(std::istream& in, Point& point)
{
  
}
