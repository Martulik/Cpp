#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <array>

#include "shape.hpp"
#include "point.hpp"

namespace murzakanov
{
  int getDistanceSquared(const Point& p1, const Point& p2);
  int calculateVertices(int vertices, const murzakanov::Shape& shp);
  void sortShapes(std::vector< murzakanov::Shape >& shps);
  std::array< int, 6 > calculateSides(const murzakanov::Shape& shp);
  murzakanov::Point returnFrontPnt(const murzakanov::Shape& shp);
}

#endif
