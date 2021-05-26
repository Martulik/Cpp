#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "point.hpp"
#include <vector>

namespace ferapontov
{
  using Shape = std::vector< Point >;

  std::istream& operator>>(std::istream& in, Shape& vec);
  std::ostream& operator<<(std::ostream& out, const Shape& vec);
}

#endif
