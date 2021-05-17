#ifndef TOOLS_HPP
#define TOOLS_HPP
#include "shape.hpp"

namespace murzakanov
{
  bool checkIsRectangle(const Shape& shp);
  bool checkIsSquare(const Shape& shp);
  bool isEqual(double op1, double op2);
  int getDistanceSquared(const Point& p1, const Point& p2);
  std::vector< int > calculateSides(const murzakanov::Shape& shp);
  int calculateVertices(const std::vector< murzakanov::Shape >& shp);
}

#endif
