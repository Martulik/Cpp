#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <vector>
#include "point.hpp"

namespace doroshin
{
  struct Shape
  {
    std::vector< Point > points_;
  };

  bool isSquare(const Shape&);
  bool isTriangle(const Shape& s);
  bool isRectangle(const Shape& s);
  bool isPentagon(const Shape& s);

  std::istream& operator>>(std::istream&, Shape&);
  std::ostream& operator<<(std::ostream&, const Shape&);
}

#endif //SHAPE_HPP
