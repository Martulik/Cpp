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

  inline bool isTriangle(const Shape& s)
  {
    return s.points_.size() == 3;
  }

  inline bool isRectangle(const Shape& s)
  {
    return s.points_.size() == 4;
  }

  inline bool isPentagon(const Shape& s)
  {
    return s.points_.size() == 5;
  }

  std::istream& operator>>(std::istream&, Shape&);
  std::ostream& operator<<(std::ostream&, const Shape&);
}

#endif //SHAPE_HPP
