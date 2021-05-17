#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iostream>
#include "point.hpp"

namespace diurdeva {
  using Shape = std::vector< Point >;

  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);

  enum ShapeType
  {
    TRIANGLE,
    SQUARE,
    RECTANGLE,
    PENTAGON,
    DEFAULT
  };

  ShapeType getType(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isTriangle(const Shape& shape);
  bool isPentagon(const Shape& shape);
}

#endif
