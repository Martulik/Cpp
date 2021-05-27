#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iosfwd>
#include "point.hpp"

namespace shilyaev {
  using Shape = std::vector< Point >;
  std::ostream &operator<<(std::ostream &ostream, const Shape &shape);
  std::istream &operator>>(std::istream &istream, Shape &shape);
  bool isTriangle(const Shape &shape);
  bool isSquare(const Shape &shape);
  bool isRectangle(const Shape &shape);
  bool isPentagon(const Shape &shape);
}

#endif
