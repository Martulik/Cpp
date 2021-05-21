#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include "point.hpp"

namespace borisova
{
  using Shape = std::vector< Point >;

  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
  bool operator<(const Shape& firstShape, const Shape& secondShape);

  bool isTriangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isRectangle(const Shape& shape);
  bool isOther(const Shape& shape);
  bool isPentagon(const Shape& shape);
};

#endif
