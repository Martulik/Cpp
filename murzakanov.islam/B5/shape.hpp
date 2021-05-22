#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <vector>
#include "point.hpp"

namespace murzakanov
{
  using Shape = std::vector< murzakanov::Point >;
  std::istream& operator>>(std::istream& in, Shape& shp);
  std::ostream& operator<<(std::ostream& out, const Shape& shp);
  bool isRectangle();
  bool isSquare();
  bool isTriangle();
}

#endif
