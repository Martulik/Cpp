#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <vector>
#include "point.hpp"

namespace ferapontov
{
  using Shape = std::vector< Point >;

  std::istream& operator>>(std::istream& in, Shape& vec);
  std::ostream& operator<<(std::ostream& out, const Shape& vec);

  bool isTriangle(const Shape& shp);
  bool isSquare(const Shape& shp);
  bool isRectangle(const Shape& shp);
  bool isPentagon(const Shape& shp);

  bool compare(const Shape& lhs, const Shape& rhs);
}

#endif
