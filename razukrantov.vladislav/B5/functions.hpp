#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "shape.hpp"
#include "point.hpp"

namespace razukrantov
{
  bool isSidesEqual(const Shape& shape);
  int getDistanceSquared(const Point& point1, const Point& point2);
}

#endif
