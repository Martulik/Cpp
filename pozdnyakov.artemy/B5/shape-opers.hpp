#ifndef SHAPE_OPERS_HPP
#define SHAPE_OPERS_HPP

#include <iosfwd>
#include "point.hpp"

namespace pozdnyakov
{
  bool isSquare(const Shape& shape);
  bool isRect(const Shape& shape);
  bool isTriangle(const Shape& shape);
  size_t sizeAccum(size_t prev, const Shape& shape);
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
}

#endif
