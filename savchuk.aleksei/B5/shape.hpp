#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iosfwd>

#include "point.hpp"

namespace savchuk
{
  using Shape = std::vector< Point >;

  std::istream& operator>>(std::istream& is, Shape& shape);
  std::ostream& operator<<(std::ostream& os, const Shape& shape);
}

#endif
