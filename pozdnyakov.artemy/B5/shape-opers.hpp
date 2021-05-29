#ifndef SHAPE_OPERS_HPP
#define SHAPE_OPERS_HPP

#include <iosfwd>
#include "point.hpp"

namespace pozdnyakov
{
  bool isSquare(Shape& shape);
  bool isRect(Shape& shape);
  bool isTriangle(Shape& shape);
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
}

#endif
