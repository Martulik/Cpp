#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iosfwd>

#include "shape.hpp"

namespace shkurov
{
  unsigned int countVertices(unsigned int sum, const Shape& cur);
  bool isTriangle(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isPentagon(const Shape& shape);
  int getSide(const Point& a, const Point& b);
  Point getPoint(const Shape& shape);
}

#endif
