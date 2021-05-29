#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "shape.hpp"
#include "point.hpp"

namespace razukrantov
{
  bool isSidesEqual(const Shape& shape);
  int getDistanceSquared(const Point& point1, const Point& point2);
  unsigned int sumVertices(unsigned int sum, const Shape& shape);
  Point getFrontPoint(const Shape& shape);
  void shapesPartition(std::vector< Shape >& shapes);
}

#endif
