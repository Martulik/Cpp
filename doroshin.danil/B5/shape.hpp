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

  std::istream& operator>>(std::istream&, Shape&);
  std::ostream& operator<<(std::ostream&, const Shape&);
}

#endif //SHAPE_HPP
