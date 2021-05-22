#ifndef TOOLS_HPP
#define TOOLS_HPP
#include "shape.hpp"
#include <array>

namespace murzakanov
{
  int getDistanceSquared(const Point& p1, const Point& p2);
  std::array< int, 6 > calculateSides(const murzakanov::Shape& shp);
  int calculateVertices(const std::vector< murzakanov::Shape >& shp);
}

#endif
