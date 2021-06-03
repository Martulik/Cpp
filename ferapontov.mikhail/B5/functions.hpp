#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "shape.hpp"

namespace ferapontov
{
  int calculateVector(const Point& first, const Point& second);
  Point getVertex(const Shape& shp);
  void sortShapes(std::vector< Shape >& shapes);
}

#endif
