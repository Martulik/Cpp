#ifndef TOOLS_HPP
#define TOOLS_HPP
#include "shape.hpp"

namespace murzakanov
{
  bool checkIsRectangle(const Shape& shp);
  bool checkIsSquare(const Shape& shp);
  bool isEqual(double op1, double op2);
  double getDistance(const Point& p1, const Point& p2);
}

#endif
